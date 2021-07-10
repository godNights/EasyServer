#include "EasyServer.h"
#include <sys/socket.h>
#include <sys/types.h>
#include "public.h"
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <sys/select.h>
#include <sys/poll.h>
#include <sys/epoll.h>
#include <testBuffer.pb.h>

EasyServer::EasyServer() :
    m_iPort(8019),
    m_sIp("127.0.0.1"),
    m_iBacklog(128)
{

}

EasyServer::EasyServer(const std::string &ip, int port, int backlog, ServerMode mode) :
    m_iPort(port),
    m_sIp(ip),
    m_iBacklog(backlog),
    m_serverMode(mode)
{

}

EasyServer::~EasyServer()
{
    close(m_iListenFd);
}

bool EasyServer::Run()
{
    if (!InitListenFd())
    {
        perror("init listen fd error!");
        return false;
    }

    switch (m_serverMode)
    {
        case SELECT:
        {
            Select();
        }
        break;
        case POLL:
        {
            Poll();
        }
        break;
        case EPOLL:
        {
            Epoll();
        }
        break;
        default:
        {
            printf("error mode[%d]\n", m_serverMode);
            return false;
        }
        break;
    }

    return true;


    /*int conFd = accept(m_iListenFd, (struct sockaddr *)&m_address, &addrLen);

    if (conFd < 0)
    {
        printf("accept error, errno[%d]\n", errno);
    }
    else
    {
        char buffer[MAX_BUF_SIZE];
        memset(buffer, 0, sizeof(buffer));

        while (true)
        {

        }
        
    }*/

}

bool EasyServer::InitListenFd()
{
    m_iListenFd = -1;
    if ((m_iListenFd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("init socket error, errno[%d]\n", errno);
        return false;
    }
     
    SetBlocking(m_iListenFd, false);

    memset(&m_address, 0, sizeof(m_address));

    m_address.sin_family = AF_INET;
    inet_pton(AF_INET, m_sIp.c_str(), &m_address.sin_addr);
    m_address.sin_port = htons(m_iPort);

    if (bind(m_iListenFd, (struct sockaddr* )&m_address, sizeof(m_address)) < 0)
    {
        printf("bind socket error, errno[%d]\n", errno);
        return false;
    }

    if (listen(m_iListenFd, m_iBacklog) < 0)
    {
        printf("connect socket error, errno[%d]\n", errno);
        return false;
    }

    return true;
}

void EasyServer::Select()
{
    socklen_t sockAddrLen = sizeof(sockaddr_in);
    struct sockaddr_in cliAddr;
    char buffer[1024];
    
    int maxFd = m_iListenFd;
    int sequence = 0;
    fd_set allSet;
    fd_set readSet;
    FD_ZERO(&allSet);
    FD_SET(m_iListenFd, &allSet);
    std::vector<int> allFd;
    
    while (true)
    {
        readSet = allSet;

        int result = select(maxFd + 1, &readSet, NULL, NULL, NULL);

        if (result < 0)
        {
            printf("select error,errno[%d]\n", errno);
            return ;
        }
        if (result == 0)
        {
            continue;
        }
        if (FD_ISSET(m_iListenFd, &readSet))
        {
            size_t len = sizeof(sockaddr_in);

            int clientFd = accept(m_iListenFd, (struct sockaddr *)&cliAddr, &sockAddrLen);
            if (clientFd < 0)
            {
                 printf("accept error, errno[%d]\n", errno);
                 continue;
            }
            printf("recv client connect[%d]\n", clientFd);
            SetBlocking(clientFd, false);
            FD_SET(clientFd, &allSet);
            allFd.push_back(clientFd);

            maxFd = maxFd > clientFd ? maxFd : clientFd;
        }
        else
        {
            for (int fd : allFd)
            {
                if (FD_ISSET(fd, &readSet))
                {
                    memset(buffer, 0, sizeof(buffer));
                    bool rtn = RecvMsg(fd, buffer);
                    if (!rtn)
                    {
                        close(fd);
                        FD_CLR(fd, &allSet);
                        continue;
                    }

                    memset(buffer, 0, sizeof(buffer));
                    ServerBuffer serverBuffer;
                    serverBuffer.set_sequence(++sequence);
                    serverBuffer.SerializePartialToArray(buffer, serverBuffer.ByteSize());

                    rtn = SendMsg(fd, buffer, serverBuffer.ByteSize());
                    if (!rtn)
                    {
                        close(fd);
                        FD_CLR(fd, &allSet);
                        continue;
                    }
                }
            }
        }         
    }
    close(m_iListenFd);
}

void EasyServer::Poll()
{

}

void EasyServer::Epoll()
{

}