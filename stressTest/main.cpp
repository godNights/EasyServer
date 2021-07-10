#include "StressTest.h"

int main(int argc, char *argv[])
{
    StressTest stressTest("127.0.0.1", 12345, 2, 20);
    stressTest.Run();

    return 0;
}