#include "StressTest.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
    std::string ip = "127.0.0.1";
    int port       = 12345;
    int connNum    = 2;
    int sendTime   = 20;
    
    int opt;
    const char *optString = "i::p::c::s::";

    while ((opt = getopt(argc, argv, optString)) != -1)
    {
        switch (opt)
        {
            case 'i':
            {
                ip = optarg;
            }
            break;
            case 'p':
            {
                port = atoi(optarg);
            }
            break;
            case 'c':
            {
                connNum = atoi(optarg);
            }
            break;
            case 's':
            {
                sendTime = atoi(optarg);
            }
            break;
            default:
            {
                printf("error opt[%c]", opt);
            }
            break;
        }
    }
    
    
    StressTest stressTest(ip, port, connNum, sendTime);
    stressTest.Run();

    return 0;
}