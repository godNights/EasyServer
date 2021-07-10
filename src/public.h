#include <stdint.h>

int  SetBlocking(int fd, bool isBlocking);
int Recv(int sockFd, char *buffer, int len);
int Send(int sockFd, const char *buffer, uint16_t len);
bool RecvMsg(int sockFd, char *buffer);
bool SendMsg(int sockFd, const char *buffer, uint16_t len);
bool GetIsLittleEndian();