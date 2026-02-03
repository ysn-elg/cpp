#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T *array, const size_t len, void (*f)(T &))
{
    for (size_t i = 0; i < len; ++i)
        f(array[i]);
}

template <typename T>
void iter(T const *array, const size_t len, void (*f)(T const &))
{
    for (size_t i = 0; i < len; ++i)
        f(array[i]);
}

#endif
