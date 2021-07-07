#include <stdint.h>

int  SetBlocking(int fd, bool isBlocking);
bool Recv(int sockFd, char *buffer);
bool Send(int sockFd, const char *buffer, uint16_t len);
bool GetIsLittleEndian();