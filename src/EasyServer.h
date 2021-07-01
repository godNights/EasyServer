#ifndef __EASY_SERVER_H
#define __EASY_SERVER_H

#include <arpa/inet.h>

const int MAX_BUF_SIZE = 1024;

class EasyServer
{
public:
    EasyServer();
    EasyServer(const char *ip, int port, int backlog = 128);
    ~EasyServer();

public:
    void Run();

private:
    bool InitListenFd();

private:
    int         m_iListenFd;
    char        m_sIp[32];
    int         m_iPort;
    int         m_iBacklog;
    sockaddr_in m_address;
};


#endif