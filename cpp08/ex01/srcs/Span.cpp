#include "Span.hpp"
#include <algorithm>

Span::Span(): _n(0), _data(0)
{

}

Span::Span(unsigned int n): _n(n), _data(0)
{

}

Span::Span(const Span& other)
{
    *this = other;
}


Span::~Span()
{

}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _n = other._n;
        _data = other._data;
    }
    
    return (*this);
}

void Span::addNumber(int num)
{
    if (_data.size() < _n)
        _data.push_back(num);
    else
        throw tooMuch();
}

int Span::shortestSpan()
{
    if (_data.size() < 2)
        throw noSpan();
    
    std::vector<int> sorted_data;
    int minSpan;

    sorted_data = _data;
    std::sort(sorted_data.begin(), sorted_data.end());
    minSpan = sorted_data[1] - sorted_data[0];

    for (size_t i = 2; i < sorted_data.size(); i++)
    {
        if (sorted_data[i] - sorted_data[i - 1] < minSpan)
            minSpan = sorted_data[i] - sorted_data[i - 1];
    }    
    return (minSpan);
}

int Span::longestSpan()
{
    if (_data.size() < 2)
        throw noSpan();
    
    std::vector<int> sorted_data = _data;
    std::sort(sorted_data.begin(), sorted_data.end());
    
    return (sorted_data[sorted_data.size() - 1] - sorted_data[0]);
}
