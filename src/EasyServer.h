#ifndef __EASY_SERVER_H
#define __EASY_SERVER_H

#include <string>
#include <arpa/inet.h>

const int MAX_BUF_SIZE = 1024;
const int MAX_POLLFD   = 1024;
const int MAX_SELECTFD = 1024;


enum ServerMode
{
    SELECT = 1,
    POLL   = 2,
    EPOLL  = 3
};

class EasyServer
{
public:
    EasyServer();
    EasyServer(const std::string &ip, int port, int backlog = 128, ServerMode mode = SELECT);
    ~EasyServer();

public:
    bool Run();

private:
    bool InitListenFd();
    void Select();
    void Poll();
    void Epoll();

private:
    int           m_iListenFd;
    std::string   m_sIp;
    int           m_iPort;
    int           m_iBacklog;
    sockaddr_in   m_address;
    ServerMode    m_serverMode;
};


#endif