#ifndef UTIL_H
#define UTIL_H

#include <cstdint>
#include <cstddef>

namespace util {

/**
 * @brief Get number of bytes required to store N bits.
 * 
 * @param n Number of bits to store
 * @return Number of bytes
 */
constexpr size_t bytes_in_bits(size_t n)
{ 
    return (n >> 3) + !!(n & 7); 
}

/**
 * @brief Integer with bit set at given position.
 * 
 * @param n Bit position
 * @return Integer with set bit
 */
constexpr unsigned bit(unsigned n) 
{ 
    return 1ul << n; 
}

/**
 * @brief Get n-th bit of a byte.
 * 
 * @param b Byte
 * @param n Bit position from LSB
 * @return Bit value
 */
constexpr bool get_bit(uint8_t b, int n)
{ 
    return (b >> n) & 1; 
}

/**
 * @brief Set n-th bit of a byte.
 * 
 * @param b Byte
 * @param n Bit position from LSB
 */
constexpr void set_bit(uint8_t &b, int n)
{ 
    b |= 1 << n; 
}

/**
 * @brief Clear n-th bit of a byte.
 * 
 * @param b Byte
 * @param n Bit position from LSB
 */
constexpr void clr_bit(uint8_t &b, int n)
{ 
    b &= ~(1 << n); 
}

/**
 * @brief Get n-th bit of an array (starting from LSB).
 * 
 * @param arr Array of bytes
 * @param n Index of bit to get
 * @return true if set
 */
constexpr bool get_arr_bit(const uint8_t *arr, int n)
{
    return get_bit(arr[n >> 3], n & 7);
}

/**
 * @brief Set n-th bit in an array of bytes (starting from LSB).
 * 
 * @param arr Array of bytes
 * @param n Index of bit to set
 */
constexpr void set_arr_bit(uint8_t *arr, int n)
{
    set_bit(arr[n >> 3], n & 7);
}

/**
 * @brief Clear n-th bit in an array of bytes (starting from LSB).
 * 
 * @param arr Array of bytes
 * @param n Index of bit to clear
 */
constexpr void clr_arr_bit(uint8_t *arr, int n)
{
    clr_bit(arr[n >> 3], n & 7);
}

}

#endif