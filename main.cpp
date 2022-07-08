#include "utl/utl.h"
#include <iostream>

int main()
{
    static_assert(utl::str_to_int("0") == 0);
    static_assert(utl::str_to_int("1") == 1);
    static_assert(utl::str_to_int("-1") == -1);
    static_assert(utl::str_to_int("12") == 12);
    static_assert(utl::str_to_int("-12") == -12);
    static_assert(utl::str_to_int("123") == 123);
    static_assert(utl::str_to_int("-123") == -123);
    static_assert(utl::str_to_int("1234") == 1234);
    static_assert(utl::str_to_int("-1234") == -1234);
    static_assert(utl::str_to_int("2147483647") == 2147483647);
    static_assert(utl::str_to_int("-2147483648") == -2147483648);

    auto start = utl::compilation_tm();

    std::cout << utl::compilation_utc() << "\n";
    std::cout << utl::timeutc(start) << "\n";

    // auto test_1 = [&]()
    // {
    //     volatile auto a = utl::time_utc(start);
    //     (void)(a);
    // };

    // auto test_2 = [&]()
    // {
    //     volatile auto a = utl::timeutc(start);
    //     (void)(a);
    // };

    // printf("1) %lu clock_t \n", utl::exec_time<10000000000>(test_1));
    // printf("2) %lu clock_t \n", utl::exec_time<10000000000>(test_2));
    // printf("1) %lu clock_t \n", utl::exec_time<10000000000>(test_1));
    // printf("2) %lu clock_t \n", utl::exec_time<10000000000>(test_2));
    // printf("1) %lu clock_t \n", utl::exec_time<10000000000>(test_1));
    // printf("2) %lu clock_t \n", utl::exec_time<10000000000>(test_2));

    // printf("1) %lu clock_t \n", utl::exec_time<100000000>(utl::time_utc, start));
    // printf("2) %lu clock_t \n", utl::exec_time<100000000>(utl::timeutc, start));
    // printf("1) %lu clock_t \n", utl::exec_time<100000000>(utl::time_utc, start));
    // printf("2) %lu clock_t \n", utl::exec_time<100000000>(utl::timeutc, start));
    // printf("1) %lu clock_t \n", utl::exec_time<100000000>(utl::time_utc, start));
    // printf("2) %lu clock_t \n", utl::exec_time<100000000>(utl::timeutc, start));

    return 0;
}
