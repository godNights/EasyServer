#include "EasyServer.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

EasyServer::EasyServer()
{
    m_iPort = 8019;
    strncpy(m_sIp, "127.0.0.1", sizeof(m_sIp) - 1);
    m_iBacklog = 128;
}

EasyServer::EasyServer(const char *ip, int port, int backlog)
{
    m_iPort = port;
    strncpy(m_sIp, ip, sizeof(m_sIp) - 1);
    m_iBacklog = backlog;
}

EasyServer::~EasyServer()
{
    close(m_iListenFd);
}

void EasyServer::Run()
{
    InitListenFd();

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
    if ((m_iListenFd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("init socket error, errno[%d]\n", errno);
        return false;
    }
     
    
    memset(&m_address, 0, sizeof(m_address));

    m_address.sin_family = AF_INET;
    inet_pton(AF_INET, m_sIp, &m_address.sin_addr);
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