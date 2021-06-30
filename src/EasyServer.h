#ifndef __EASY_SERVER_H
#define __EASY_SERVER_H

class EasyServer
{
public:
    EasyServer();
    EasyServer(const char *ip, int port, int backlog = 128);
    ~EasyServer();

public:
    void Run();

private:
    bool InitListenSocket();

private:
    int  m_iListenSocket;
    char m_sIp[32];
    int  m_iPort;
    int  m_iBacklog;
};


#endif