#ifndef UTL_CONTAINER_H
#define UTL_CONTAINER_H

#include "utl/base.h"

namespace utl {

/**
 * @brief Resizable static vector with pre-allocated memory on stack.
 * 
 * @tparam T Type of elements
 * @tparam N Maximum number of elements
 */
template<class T, size_t N>
struct svector {
    // Get capacity of the vector.
    constexpr size_t capacity() const       { return N; }
    // Get size of the vector.
    constexpr size_t size() const           { return len; }
    // Check if the vector is empty.
    constexpr bool empty() const            { return len == 0; }
    // Check if the vector is full.
    constexpr bool full() const             { return len == N; }
    // Get element at index.
    constexpr T& operator[](size_t i) const { return buf[i]; }
    // Get element at index without const.
    constexpr T& operator[](size_t i)       { return buf[i]; }
    // Get pointer to the beginning of the vector.
    constexpr T* begin() const              { return buf; }
    // Get pointer to the beginning of the vector.
    constexpr T* begin()                    { return buf; }
    // Get pointer to the end of the vector.
    constexpr T* end() const                { return buf + len; }
    // Get pointer to the end of the vector.
    constexpr T* end()                      { return buf + len; }
    // Get pointer to the beginning of the vector.
    constexpr T* data() const               { return buf; }
    // Get pointer to the beginning of the vector.
    constexpr T* data()                     { return buf; }
    // Clear the vector.
    constexpr void clear()                  { len = 0; }
    // Resize the vector.
    constexpr void resize(size_t size)      { if (size <= N) len = size; }
    // Push element to the end of the vector.
    constexpr void push_back(const T &x)    { if (len < N) buf[len++] = x; }
    // Pop element from the end of the vector.
    constexpr void pop_back()               { if (len > 0) --len; }
    // Erase element at iterator.
    constexpr void erase(T *p)
    {
        if (!len || p == &buf[--len])
            return;
        *p = buf[len];
    }
private:
    T buf[N];
    size_t len = 0;
};

}

#endif