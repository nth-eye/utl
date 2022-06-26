#include <cstring>
#include <cstdio>
#include <ctime>
#include "utl/utl.h"

template<size_t N = 1, class Fn, class ...Args>
clock_t measure_time(Fn &&fn, Args &&...args)
{
    clock_t begin = clock();
    for (size_t i = 0; i < N; ++i) 
        fn(args...);
    clock_t end = clock();

    return (end - begin); // / N;
}

int main()
{

    // printf("1: %3ld clock_t\n", measure_time<100000000>(utl::str_to_dbl, str, len));
    // printf("2: %3ld clock_t\n", measure_time<100000000>(utl::str_to_float, str, len));
    // printf("1: %3ld clock_t\n", measure_time<100000000>(utl::str_to_dbl, str, len));
    // printf("2: %3ld clock_t\n", measure_time<100000000>(utl::str_to_float, str, len));
    // printf("1: %3ld clock_t\n", measure_time<100000000>(utl::str_to_dbl, str, len));
    // printf("2: %3ld clock_t\n", measure_time<100000000>(utl::str_to_float, str, len));
    // printf("1: %3ld clock_t\n", measure_time<100000000>(utl::str_to_dbl, str, len));
    // printf("2: %3ld clock_t\n", measure_time<100000000>(utl::str_to_float, str, len));
    // printf("1: %3ld clock_t\n", measure_time<100000000>(utl::str_to_dbl, str, len));
    // printf("2: %3ld clock_t\n", measure_time<100000000>(utl::str_to_float, str, len));

    uint8_t arr[] = { 0x54, 0x00, 0x34 };

    utl::log_bits(arr, sizeof(arr) * 8, 0);
    utl::log_hex(arr, sizeof(arr));
    utl::log_hex_with_addr(arr, sizeof(arr));
}
