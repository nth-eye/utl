#ifndef UTL_LOG_H
#define UTL_LOG_H

#include "utl/bit.h"
#include <cctype>
#include <cstdio>

namespace utl {
namespace detail {

inline void log_hex_impl(const void *data, size_t len, void (*line_begin_cb)(const uint8_t *))
{
    if (!data || !len)
        return;

    const uint8_t *p = static_cast<const uint8_t*>(data);

    for (size_t i = 0; i < len; ++i) {

        if (!(i & 15))
            line_begin_cb(p + i);

        printf("%02x ", p[i]);
        
        if ((i & 7) == 7)
            putchar(' ');

        if ((i & 15) == 15) {
            putchar('|');
            for (int j = 15; j >= 0; --j) {
                char c = p[i - j];
                putchar(isprint(c) ? c : '.');
            }
            printf("|\n");
        }
    }
    int rem = len - ((len >> 4) << 4);
    if (rem) {
        printf("%*c |", (16 - rem) * 3 + ((~rem & 8) >> 3), ' ');
        for (int j = rem; j; --j) {
            char c = p[len - j];
            putchar(isprint(c) ? c : '.');
        }
        for (int j = 0; j < 16 - rem; ++j)
            putchar('.');
        printf("|\n");
    }
}

}

/**
 * @brief Print bits nicely from offset position with MSB at left and relevant ASCII.
 * 
 * @param data Memory with bits to log
 * @param len Number of bits
 * @param pos Bit offset in initial byte, be careful to not go out of memory region
 */
inline void log_bits(const void *data, size_t len, size_t pos)
{
    printf("[%08llx]: %lu bits with %lu offset \n", (long long unsigned) data, len, pos);

    if (!data || !len)
        return;

    auto p = static_cast<const uint8_t*>(data);
    auto off = pos & 7;
    auto rem = len & 7;

    uint8_t line[8];

    for (size_t i = 0; i < len; ++i) {

        if (!(i & 63))
            printf("[%08llx : %lu]  ", (long long unsigned) data + (pos >> 3), off);

        if (get_arr_bit(p, pos++))
            set_arr_bit(line, i & 63);
        else
            clr_arr_bit(line, i & 63);
            
        if (rem && i == len - i) {
            uint8_t c = line[(i & 63) >> 3];
            for (int j = rem - 1; j >= 0; --j)
                putchar(get_bit(c, j) + '0');
        }

        if ((i & 7) == 7) {
            uint8_t c = line[(i & 63) >> 3];
            for (int j = 7; j >= 0; --j)
                putchar(get_bit(c, j) + '0');
            putchar(' ');
        }

        if ((i & 63) == 63) {
            printf(" |");
            for (int j = 0; j < 8; ++j) {
                char c = line[j];
                putchar(isprint(c) ? c : '.');
            }
            printf("|\n");
        }
    }

    int rem_bits = len - ((len >> 6) << 6);
    int rem_bytes = rem_bits >> 3;
    int fill_bits = 64 - rem_bits;
    int fill_bytes = fill_bits >> 3;

    if (rem_bits) {

        printf("%*c |", int(fill_bits + bytes_in_bits(fill_bits)), ' ');

        for (int j = 0; j < rem_bytes; ++j) {
            char c = line[j];
            putchar(isprint(c) ? c : '.');
        }
        if (rem)
            putchar('.');
        for (int j = 0; j < fill_bytes; ++j)
            putchar('.');
        printf("|\n");
    }
}

/**
 * @brief Print hex nicely with relevant ASCII representation.
 * 
 * @param data Data to print
 * @param len Length in bytes
 */
inline void log_hex(const void *data, size_t len)
{
    auto cb = []([[maybe_unused]] const uint8_t *addr) {
        printf("| ");
    };
    detail::log_hex_impl(data, len, cb);
}

/**
 * @brief Print hex nicely with relevant ASCII representation and 
 * memory address column.
 * 
 * @param data Data to print
 * @param len Length in bytes
 */
inline void log_hex_with_addr(const void *data, size_t len)
{
    printf("[%08llx]: %lu bytes \n", (long long unsigned) data, len);

    auto cb = [](const uint8_t *addr) {
        printf("[%08llx]  ", (long long unsigned) addr);
    };
    detail::log_hex_impl(data, len, cb);
}

}

#endif
