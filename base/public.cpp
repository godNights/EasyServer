#include "public.h"
#include <fcntl.h>
#include <string.h>
#include <arpa/inet.h>

int SetBlocking(int fd, bool isBlocking)
{
    int oldOption = fcntl(fd, F_GETFL);
    int newOption;
    if (isBlocking)
    {
        newOption &= ~O_NONBLOCK;
    }
    else
    {
        newOption |= O_NONBLOCK;
    }
    fcntl(fd, F_SETFL, newOption);

    return oldOption;
}

bool GetIsLittleEndian()
{
    //0X00 0X01
    unsigned int i = 1;
    return *(char *)(&i) == 1;
}

bool Recv(int sockFd, char *buffer)
{
    memset(buffer, 0, sizeof(buffer));

    char lenBuffer[sizeof(uint16_t) + 1] = { 0 };
    recv(sockFd, lenBuffer, sizeof(uint16_t), 0);

    uint16_t len = *(uint16_t*)(lenBuffer);

    if (GetIsLittleEndian())
    {
        len = ntohs(len);
    }

    while (len > 0)
    {
        int recvSize = recv(sockFd, buffer, len, 0);
        if (recvSize <= 0)
        {
            return false;
        }
        len -= recvSize;
        buffer += recvSize;
    }
}

bool Send(int sockFd, const char *buffer, uint16_t len)
{
    char lenBuffer[sizeof(uint16_t) + 1] = { 0 };
    uint16_t *lenPtr = (uint16_t*)lenBuffer;
    *lenPtr = htons(len);

    send(sockFd, lenBuffer, sizeof(uint16_t), 0);
    
    while (len > 0)
    {
        int sendSize = send(sockFd, buffer, len, 0);
        if (sendSize <= 0)
        {
            return false;
        }
        len -= sendSize;
        buffer += sendSize;
    }
    return true;
}