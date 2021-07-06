#ifndef __STRESS_TEST_H
#define __STRESS_TEST_H

#include <string>

const int MAX_EVENTS = 10000;

class StressTest
{
public:
    StressTest(const std::string &ip, int port, int connNum);
    ~StressTest();

public:
    bool Run();
    int  SetBlocking(int fd, bool isBlocking);
    void AddFd(int fd);
    int  CreateConn(int num);
    void CloseConn(int fd);

private:
    int         m_iEpollFd;
    std::string m_sIp;
    int         m_iPort;
    int         m_iConnNum;
};


#endif