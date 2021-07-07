#include "EasyServer.h"

int main(int argc, char *argv[])
{
    EasyServer server("127.0.0.1", 12345);
    server.Run();

    return 0;
}