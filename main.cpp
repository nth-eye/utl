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
    const char *str = "666.1239876";
    const size_t len = strlen(str);

    // printf("1: %3ld clock_t\n", measure_time<100000000>(util::str_to_dbl, str, len));
    // printf("2: %3ld clock_t\n", measure_time<100000000>(util::str_to_float, str, len));
    // printf("1: %3ld clock_t\n", measure_time<100000000>(util::str_to_dbl, str, len));
    // printf("2: %3ld clock_t\n", measure_time<100000000>(util::str_to_float, str, len));
    // printf("1: %3ld clock_t\n", measure_time<100000000>(util::str_to_dbl, str, len));
    // printf("2: %3ld clock_t\n", measure_time<100000000>(util::str_to_float, str, len));
    // printf("1: %3ld clock_t\n", measure_time<100000000>(util::str_to_dbl, str, len));
    // printf("2: %3ld clock_t\n", measure_time<100000000>(util::str_to_float, str, len));
    // printf("1: %3ld clock_t\n", measure_time<100000000>(util::str_to_dbl, str, len));
    // printf("2: %3ld clock_t\n", measure_time<100000000>(util::str_to_float, str, len));

    printf("%f\n", utl::str_to_dbl(str, len));
    // printf("%f\n", util::str_to_float(str, len));
}
