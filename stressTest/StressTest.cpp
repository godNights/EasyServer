#include "StressTest.h"
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

StressTest::StressTest(const std::string &ip, int port, int connNum) :
    m_sIp(ip),
    m_iPort(port),
    m_iConnNum(connNum)
{
    
}

StressTest::~StressTest()
{

}

bool StressTest::Run()
{
    m_iEpollFd = epoll_create(1024);
    if (m_iEpollFd == -1)
    {
        printf("epoll create error, errno[%d]", errno);
        return false;
    }

    int createSuccess = CreateConn(m_iConnNum);
    printf("success create socket[%d]\n", createSuccess);
    epoll_event events[MAX_EVENTS];
    while (true)
    {
        int fds = epoll_wait(m_iEpollFd, events, MAX_EVENTS, 2000);
        for (int i = 0; i != fds; ++i)
        {
            int sockFd = events[i].data.fd;
            if (events[i].events & EPOLLIN)
            {

            }
            else if (events[i].events & EPOLLOUT)
            {

            }
            else if (events[i].events & EPOLLERR)
            {
                CloseConn(sockFd);
            }
        }
    }

}

int StressTest::SetBlocking(int fd, bool isBlocking)
{
    int oldOption = fcntl(fd, F_GETFL);
    int newOption;
    if (isBlocking)
    {
        newOption &= ~O_NONBLOCK;
    }
    else
    {
        newOption |= O_NONBLOCK;
    }
    fcntl(fd, F_SETFL, newOption);

    return oldOption;
}

void StressTest::AddFd(int fd)
{
    epoll_event event;
    event.data.fd = fd;
    event.events  = EPOLLOUT | EPOLLET | EPOLLERR;
    epoll_ctl(m_iEpollFd, EPOLL_CTL_ADD, fd, &event);
    SetBlocking(fd, false);
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
        ++createSuccess;
    }
    return createSuccess;
}