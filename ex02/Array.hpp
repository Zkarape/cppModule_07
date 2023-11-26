#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
    T *_array;
    unsigned int _n;

public:
    T *getArray() const;
    Array() : _n(0)
    {
        std::cout << "Default Constructor called and created empty Array of size 0" << std::endl;
        _array = new T[_n];
    }

    // parametrized constructor
    Array(unsigned int n) : _n(n)
    {
        std::cout << "Parametrized Constructor called and created empty Array of size 0" << std::endl;
        _array = new T[n];
    }

    // copy constructor
    Array(const Array &cpy) : _n(cpy._n)
    {
        std::cout << "Copy Constuctor called" << std::endl;
        for (int i = 0; i < _n; i++)
        {
            _array[i] = cpy._array[i];
        }
    }

    // assignment op overload
    Array &operator=(const Array &assign)
    {
        if (this->_array)
            delete[] _array;
        if (this = &assign)
            return *this;
        _n = assign._n;
        _array = new T[_n];
        for (int i = 0; i < _n; i++)
        {
            _array[i] = assign._array[i];
        }
        return (*this);
    }

    //[] operator overload
    T &operator[](unsigned int i) const
    {
        if (i >= 0 && i < _n)
            return (_array[i]);
        throw std::exception();
    }
    unsigned int size() const
    {
        return (_n);
    }
    class OutOfBoundException : public std::exception
    {
        const char *what() const throw();
    };
    // destructor
    ~Array()
    {
        delete[] _array;
    }
};

template <typename T>
const char *Array<T>::OutOfBoundException::what() const throw()
{
    return ("Index is out of bounds\n");
}

template <typename T>
T *Array<T>::getArray() const
{
    return (_array);
}

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> &arr)
{
    T *membArray = arr.getArray();
    unsigned int size = arr.size();

    o << "[";
    for (size_t i = 0; i < size; ++i)
    {
        o << membArray[i];
        if (i < size - 1)
        {
            o << ", ";
        }
    }
    o << "]" << std::endl;
    return (o);
}

#endif