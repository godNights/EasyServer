#ifndef __EASY_SERVER_H
#define __EASY_SERVER_H

#include <string>
#include <arpa/inet.h>

const int MAX_BUF_SIZE = 1024;

class EasyServer
{
public:
    EasyServer();
    EasyServer(const std::string &ip, int port, int backlog = 128);
    ~EasyServer();

public:
    bool Run();
    int  SetBlocking(int fd, bool isBlocking);

private:
    bool InitListenFd();

private:
    int           m_iListenFd;
    std::string   m_sIp;
    int           m_iPort;
    int           m_iBacklog;
    sockaddr_in   m_address;
};


#endif