#include "StressTest.h"
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "public.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <thread>


StressTest::StressTest(const std::string &ip, int port, int connNum, int sendTime) :
    m_sIp(ip),
    m_iPort(port),
    m_iConnNum(connNum),
    m_iSendTime(sendTime),
    m_iSendCount(0),
    m_iRecvCount(0),
    m_bSendComplete(false)
{
    
}

StressTest::~StressTest()
{
    close(m_iEpollFd);
}

bool StressTest::Run()
{
    time_t beginTime = time(NULL);
    m_iEpollFd = epoll_create(1024);
    if (m_iEpollFd == -1)
    {
        printf("epoll create error, errno[%d]", errno);
        return false;
    }

    int createSuccess = CreateConn(m_iConnNum);
    printf("success create socket[%d]\n", createSuccess);
    std::thread sendThread(&StressTest::SendThread, this);
    std::thread recvThread(&StressTest::RecvThread, this);

    sendThread.join();
    printf("message send complete, count[%d], time[%d]\n", m_iSendCount, time(NULL) - beginTime);
    recvThread.join();
    printf("message recv complete, count[%d], time[%d]\n", m_iRecvCount, time(NULL) - beginTime);
    return true;
}

void StressTest::SendThread()
{
    time_t beginTime = time(NULL);
    char buffer[1024] = { 0 };
    ClientBuffer clientBuffer;
    int sequence = 0;
    while ((time(NULL) - beginTime) < m_iSendTime)
    {
        usleep(10);
        for (size_t i = 0; i < m_vClientFds.size(); ++i)
        {
            memset(buffer, 0, sizeof(buffer));
            clientBuffer.Clear();
            clientBuffer.set_sockfd(m_vClientFds[i]);
            clientBuffer.set_sequence(sequence);
            clientBuffer.set_text("stressTest");
            clientBuffer.SerializePartialToArray(buffer, clientBuffer.ByteSize());

            SendMsg(m_vClientFds[i], buffer, clientBuffer.ByteSize());
            ++sequence;
            ++m_iSendCount;
        }
    }
    m_bSendComplete = true;
}

void StressTest::RecvThread()
{
    epoll_event events[MAX_EVENTS];

    while (true)
    {
        int fds = 0;
        do
        {
            fds = epoll_wait(m_iEpollFd, events, MAX_EVENTS, 5000);
        } while (fds < 0 && errno == EINTR);
        
        if (fds == 0)
        {
            return ;
        }
        if (fds < 0)
        {
            printf("epoll_wait error, errno[%d]\n", errno);
        }
        for (int i = 0; i < fds; ++i)
        {
            int sockFd = events[i].data.fd;
            if (events[i].events & EPOLLIN)
            {
                char buffer[1024];
                RecvMsg(sockFd, buffer);
                ++m_iRecvCount;
                if (m_iRecvCount >= m_iSendCount && m_bSendComplete)
                {
                    return ;
                }
            }
            else if (events[i].events & EPOLLERR)
            {
                CloseConn(sockFd);
            }
        }
    }
}


void StressTest::AddFd(int fd)
{
    epoll_event event;
    event.data.fd = fd;
    event.events  = EPOLLIN | EPOLLET | EPOLLERR;
    epoll_ctl(m_iEpollFd, EPOLL_CTL_ADD, fd, &event);
    SetBlocking(fd, false);
    m_vClientFds.push_back(fd);
}

void StressTest::CloseConn(int fd)
{
    epoll_ctl(m_iEpollFd, EPOLL_CTL_DEL, fd, 0);
    close(fd);
}

int StressTest::CreateConn(int num)
{
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET, m_sIp.c_str(), &address.sin_addr);
    address.sin_port = htons(m_iPort);
    int createSuccess = 0;

    for (int i = 0; i != num; ++i)
    {
        int sockFd = socket(PF_INET, SOCK_STREAM, 0);
        if (sockFd < 0)
        {
            continue;
        }
        if (connect(sockFd, (struct sockaddr *)&address, sizeof(sockaddr_in)) < 0)
        {
            continue;
        }
        AddFd(sockFd);
        printf("create connect[%d]\n", sockFd);
        ++createSuccess;
    }
    return createSuccess;
}
