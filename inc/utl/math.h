#ifndef UTL_MATH_H
#define UTL_MATH_H

#include "utl/base.h"

namespace utl {

/**
 * @brief Unsigned integer division with round up.
 * 
 * @tparam T Unsigned integer type
 * @param dividend Unsigned
 * @param divisor Unsigned, can be 0
 * @return Quotient
 */
template<class T>
constexpr T uceil(T dividend, T divisor)
{
    return divisor ? (dividend + (divisor - 1)) / divisor : 0;
}

/**
 * @brief Map integer from one range to another.
 * 
 * @tparam T Integer type
 * @param val Input value
 * @param in_min Input minimum
 * @param in_max Input maximum
 * @param out_min Output range minimum 
 * @param out_max Output range maximum
 * @return Result
 */
template<class T>
constexpr T imap(T val, T in_min, T in_max, T out_min, T out_max)
{
    double slope = 1.0 * (out_max - out_min) / (in_max - in_min);
    return out_min + slope * (val - in_min);
}

/**
 * @brief Integer power function.
 * 
 * @tparam T Integer type
 * @param base Base
 * @param exp Exponent
 * @return 'base' to the power 'exp'
 */
template<class T>
constexpr T ipow(T base, T exp)
{
    T res = 1;
    while (exp) {
        if (exp & 1)
            res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

/**
 * @brief Get length of integer in symbols. 10 => 2, 100 => 3, etc.
 * 
 * @tparam T Integer type
 * @param val Integer value
 * @return Length  
 */
template<class T>
constexpr T ilen(T val)
{
    T l = !val;
    while (val) { 
        ++l; 
        val /= 10; 
    }
    return l;
}

/**
 * @brief Factorial.
 * 
 * @tparam T Integer type
 * @param x Argument
 * @return Result
 */
template<class T>
constexpr T fact(T x)
{
    T res = x;
    while (--x) 
        res *= x;
    return res;
}

}

#endif