#include "public.h"
#include <fcntl.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <errno.h>

int SetBlocking(int fd, bool isBlocking)
{
    int oldOption = fcntl(fd, F_GETFL);
    int newOption = oldOption;
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

int Recv(int sockFd, char *buffer, int len)
{
    while (true)
    {
        int rtn = recv(sockFd, buffer, len, 0);

        if (rtn == 0)
        {
            return 0;
        }
        else if (rtn < 0)
        {
            if (errno == EAGAIN)
            {
                continue;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return rtn;
        }
    }  
}

int Send(int sockFd, const char *buffer, uint16_t len)
{
    while (true)
    {
        int rtn = send(sockFd, buffer, len, MSG_NOSIGNAL);

        if (rtn == 0)
        {
            return 0;
        }
        else if (rtn < 0)
        {
            if (errno == EAGAIN)
            {
                continue;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return rtn;
        }
    }  
}

bool RecvMsg(int sockFd, char *buffer)
{
    memset(buffer, 0, sizeof(buffer));
    int recvSize = 0;

    char lenBuffer[sizeof(uint16_t) + 1] = { 0 };
    recvSize = Recv(sockFd, lenBuffer, sizeof(uint16_t));
    if (recvSize == 0)
    {
        printf("client is disconnet,fd[%d]\n", sockFd);
        return false;
    }

    if (recvSize == -1)
    {
        printf("recvMsg error,fd[%d], errno[%d]\n", sockFd, errno);
        return false;
    }

    uint16_t len = *(uint16_t*)(lenBuffer);

    if (GetIsLittleEndian())
    {
        len = ntohs(len);
    }

    while (len > 0)
    {
        int recvSize = Recv(sockFd, buffer, len);
        if (recvSize == 0)
        {
            printf("client is disconnet,fd[%d]\n", sockFd);
            return false;
        }

        if (recvSize == -1)
        {
            printf("recvMsg error,fd[%d], errno[%d]\n", sockFd, errno);
            return false;
        }

        len -= recvSize;
        buffer += recvSize;
    }
    return true;
}

bool SendMsg(int sockFd, const char *buffer, uint16_t len)
{
    char lenBuffer[sizeof(uint16_t) + 1] = { 0 };
    uint16_t *lenPtr = (uint16_t*)lenBuffer;
    *lenPtr = htons(len);
    int sendSize = 0;

    sendSize = Send(sockFd, lenBuffer, sizeof(uint16_t));

    if (sendSize == 0)
    {
        printf("client is disconnet,fd[%d]\n", sockFd);
        return false;
    }

    if (sendSize == -1)
    {
        printf("sendMsg error,fd[%d], errno[%d]\n", sockFd, errno);
        return false;
    }
    
    while (len > 0)
    {
        sendSize = send(sockFd, buffer, len, MSG_NOSIGNAL);

        if (sendSize == 0)
        {
            printf("client is disconnet,fd[%d]\n", sockFd);
            return false;
        }
        
        if (sendSize == -1)
        {
            printf("sendMsg error,fd[%d], errno[%d]\n", sockFd, errno);
            return false;
        }
        len -= sendSize;
        buffer += sendSize;
    }
    return true;
}