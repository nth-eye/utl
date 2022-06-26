#ifndef UTL_TIME_H
#define UTL_TIME_H

#include "utl/base.h"
#include <ctime>

namespace utl {

template<size_t N = 1, class Fn, class ...Args>
clock_t exec_time(Fn &&fn, Args &&...args)
{
    clock_t begin = clock();
    for (size_t i = 0; i < N; ++i) 
        fn(args...);
    clock_t end = clock();

    return (end - begin);
}

template<size_t N = 1, class ...Args>
clock_t exec_time_avg(Args &&...args)
{
    return exec_time<N>(args...) / N;
}

}

#endif