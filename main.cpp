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

    return 0;
}
