#include "StressTest.h"

int main(int argc, char *argv[])
{
    StressTest stressTest("127.0.0.1", 8019, 500);
    stressTest.Run();

    return 0;
}