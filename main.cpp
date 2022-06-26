#include "utl/utl.h"

int main()
{
    // printf("1: %3ld clock_t\n", utl::exec_time<10000>(utl::log_hex, arr, sizeof(arr)));
    // printf("2: %3ld clock_t\n", utl::exec_time<10000>(utl::log_hex_putchar, arr, sizeof(arr)));

    uint8_t arr[17] = { 0x54, 0x01, 0x00, 0x34 };

    // utl::log_hex(arr, sizeof(arr));
    utl::log_bits(arr, sizeof(arr) * 8 - 0, 0);
}
