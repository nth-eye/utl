#ifndef UTL_CONTAINER_H
#define UTL_CONTAINER_H

#include "utl/base.h"
#include <array>

namespace utl {
namespace detail {

template<class T, size_t N, class Storage>
struct svector_base {

    // Get capacity of the vector.
    constexpr size_t capacity() const               { return N; }
    // Get size of the vector.
    constexpr size_t size() const                   { return len; }
    // Check if the vector is empty.
    constexpr bool empty() const                    { return len == 0; }
    // Check if the vector is full.
    constexpr bool full() const                     { return len == N; }
    // Get element at index.
    constexpr const T& operator[](size_t i) const   { return buf[i]; }
    // Get element at index without const.
    constexpr T& operator[](size_t i)               { return buf[i]; }
    // Get pointer to the beginning of the vector.
    constexpr const T* begin() const                { return buf; }
    // Get pointer to the beginning of the vector.
    constexpr T* begin()                            { return buf; }
    // Get pointer to the end of the vector.
    constexpr const T* end() const                  { return buf + len; }
    // Get pointer to the end of the vector.
    constexpr T* end()                              { return buf + len; }
    // Get pointer to the beginning of the vector.
    constexpr const T* data() const                 { return buf; }
    // Get pointer to the beginning of the vector.
    constexpr T* data()                             { return buf; }
    // Clear the vector.
    constexpr void clear()                          { len = 0; }
    // Resize the vector.
    constexpr void resize(size_t size)              { if (size <= N) len = size; }
    // Push element to the end of the vector.
    constexpr void push_back(const T &x)            { if (len < N) buf[len++] = x; }
    // Pop element from the end of the vector.
    constexpr void pop_back()                       { if (len > 0) --len; }
    // Erase element at iterator.
    constexpr void erase(T *p)
    {
        if (!len || p == &buf[--len])
            return;
        *p = buf[len];
    }
private:
    Storage buf;
    size_t len = 0;
};

}

/**
 * @brief Uninitialized storage container for any type. Uses raw byte array
 * as underlying storage. Because of this, cannot be used in constexpr 
 * context, but objects constructed on demand and not at "allocation" time.
 * Converts implicitly to pointer of underlying type.
 * 
 * @tparam T Type of elements.
 * @tparam N Number of elements.
 */
template<class T, size_t N>
struct storage {
    operator auto()         { return reinterpret_cast<T*>(buf); }
    operator auto() const   { return reinterpret_cast<const T*>(buf); }
private:
    alignas(T) unsigned char buf[sizeof(T)][N];
};

/**
 * @brief Constexpr storage container for any type. Uses regular C array 
 * as underlying storage. Because of this, objects are always default 
 * constructed at "allocation" time, but can be used in constexpr context. 
 * Converts implicitly to pointer of underlying type.
 * 
 * @tparam T Type of elements.
 * @tparam N Number of elements.
 */
template<class T, size_t N>
struct ce_storage {
    constexpr operator auto()       { return static_cast<T*>(buf); }
    constexpr operator auto() const { return static_cast<const T*>(buf); }
private:
    T buf[N]{};
};

/**
 * @brief Resizable static vector with pre-allocated memory on stack.
 * Uses utl::storage, so no constexpr support, but doesn't default 
 * construct elements. More efficient than utl::ce_svector at run-time.
 * 
 * @tparam T Type of elements
 * @tparam N Maximum number of elements
 */
template<class T, size_t N>
struct svector : detail::svector_base<T, N, storage<T, N>> {};

/**
 * @brief Resizable static vector with pre-allocated memory on stack.
 * Uses utl::ce_storage, so has constexpr support at the cost of default 
 * object construction. Less efficient than utl::svector at run-time.
 * 
 * @tparam T Type of elements
 * @tparam N Maximum number of elements
 */
template<class T, size_t N>
struct ce_svector : detail::svector_base<T, N, ce_storage<T, N>> {};

}

#endif