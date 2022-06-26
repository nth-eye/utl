#include <cstring>
#include <cstdio>
#include <ctime>
#include <chrono>
#include <thread>
#include "utl/utl.h"

int main()
{
    auto test = []()
    {
        for (int i = 0; i < 1000000000; ++i);
    };

    printf("1: %3ld clock_t\n", utl::exec_time<10>(test));
    printf("2: %3ld clock_t\n", utl::exec_time_avg<10>(test));

    // uint8_t arr[] = { 0x54, 0x00, 0x34 };

    // utl::log_bits(arr, sizeof(arr) * 8, 0);
}
