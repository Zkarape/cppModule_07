#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <cctype>

template <typename T>
void iter(T *var, size_t len, void(*foo)(T &))
{
    if (array == NULL || foo == NULL)
        return;
    for (int i = 0; i < len; i++)
    {
        foo(var[i]);
    }
}

#endif