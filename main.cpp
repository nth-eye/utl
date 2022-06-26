#include "utl/utl.h"

int main()
{
    // printf("1: %3ld clock_t\n", utl::exec_time<1000000>(utl::bin_to_char, 0x42));

    uint8_t arr[9] = { 0x54, 0x01, 0x00, 0x34 };

    utl::log_bits(arr, sizeof(arr) * 8 - 0, 0);
}
