#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class Array 
{
    private :
        T *_array;
        unsigned int _size;
    public :
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();
        T& operator[](unsigned int i);
        unsigned int size();
};

#include "../srcs/Array.tpp"
#endif