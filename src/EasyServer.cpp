#include "EasyServer.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
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
    close(m_iListenSocket);
}

void EasyServer::Run()
{
    InitListenSocket();
}

bool EasyServer::InitListenSocket()
{
    m_iListenSocket = -1;
    if ((m_iListenSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("init socket error, errno[%d]\n", errno);
        return false;
    }
     
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));

    address.sin_family = AF_INET;
    inet_pton(AF_INET, m_sIp, &address.sin_addr);
    address.sin_port = htons(m_iPort);

    if (bind(m_iListenSocket, (struct sockaddr* )&address, sizeof(address)) < 0)
    {
        printf("bind socket error, errno[%d]\n", errno);
        return false;
    }

    if (listen(m_iListenSocket, m_iBacklog) < 0)
    {
        printf("connect socket error, errorno[%d]\n", errno);
        return false;
    }

    return true;
}