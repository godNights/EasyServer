#include "EasyServer.h"
#include "Login.pb.h"

int main(int argc, char *argv[])
{
    EasyServer server("127.0.0.1", 12345, 3);
    server.Run()


    return 0;
}