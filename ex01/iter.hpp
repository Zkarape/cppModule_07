#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <cctype>

template <typename T>
void iter(T *var, size_t len, void(*foo)(T const &))
{
    if (var == NULL || foo == NULL)
        return;
    for (size_t i = 0; i < len; i++)
    {
        foo(var[i]);
    }
}

#endif