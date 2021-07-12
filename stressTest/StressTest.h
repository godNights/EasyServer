#ifndef __STRESS_TEST_H
#define __STRESS_TEST_H

#include <string>
#include "testBuffer.pb.h"
#include <vector>

const int MAX_EVENTS = 10000;
const int BUFF_SIZE  = 1024;

class StressTest
{
public:
    StressTest(const std::string &ip, int port, int connNum, int sendTime);
    ~StressTest();

public:
    bool Run();
    void AddFd(int fd);
    int  CreateConn(int num);
    void CloseConn(int fd);
    void SendThread();
    void RecvThread();

private:
    int              m_iEpollFd;
    std::string      m_sIp;
    int              m_iPort;
    int              m_iConnNum;
    int              m_iSendTime;
    int              m_iSendCount;
    int              m_iRecvCount;
    std::vector<int> m_vClientFds;
    bool             m_bSendComplete;
};


#endif