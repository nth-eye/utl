#ifndef UTL_TIME_H
#define UTL_TIME_H

#include "utl/base.h"
#include <ctime>

namespace utl {

/**
 * @brief Measure execution time of a function.
 * 
 * @tparam N Number of calls.
 * @tparam Fn Function pointer
 * @tparam Args Arguments of the function
 * @param fn Function pointer
 * @param args Arguments of the function
 * @return Total clock ticks for N executions.
 */
template<size_t N = 1, class Fn, class ...Args>
clock_t exec_time(Fn &&fn, Args &&...args)
{
    clock_t begin = clock();
    for (size_t i = 0; i < N; ++i) 
        fn(args...);
    clock_t end = clock();

    return (end - begin);
}

/**
 * @brief Measure average execution time of a function for N calls.
 * 
 * @tparam N Number of calls.
 * @tparam Args Function pointer followed by arguments.
 * @param args Function pointer followed by arguments.
 * @return Average clock ticks for each call.
 */
template<size_t N = 1, class ...Args>
clock_t exec_time_avg(Args &&...args)
{
    return exec_time<N>(args...) / N;
}

}

#endif