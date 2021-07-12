#include "EasyServer.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
    std::string ip       = "127.0.0.1";
    int port             = 12345;
    int backlog          = 128; 
    ServerMode mode      = POLL;
    
    int opt;
    const char *optString = "i::p::b::m::";

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
            case 'b':
            {
                backlog = atoi(optarg);
            }
            break;
            case 'm':
            {
                mode = ServerMode(atoi(optarg));
            }
            break;
            default:
            {
                printf("error opt[%c]", opt);
            }
            break;
        }
    }
  
    EasyServer server(ip, port, backlog, mode);
    server.Run();

    return 0;
}