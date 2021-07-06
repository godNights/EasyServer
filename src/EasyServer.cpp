#include "EasyServer.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

EasyServer::EasyServer() :
    m_iPort(8019),
    m_sIp("127.0.0.1"),
    m_iBacklog(128)
{

}

EasyServer::EasyServer(const std::string &ip, int port, int backlog) :
    m_iPort(port),
    m_sIp(ip),
    m_iBacklog(backlog)
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

    socklen_t addrLen = sizeof(m_address);

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
        printf("connect socket error, errorno[%d]\n", errno);
        return false;
    }

    return true;
}

int EasyServer::SetBlocking(int fd, bool isBlocking)
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