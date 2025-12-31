#ifndef SPAN_HPP
#define SPAN_HPP
    
#include <iostream>
#include <vector>

class tooMuch : public std::exception
{
	virtual const char *what() const throw()
	{
		return "Too much number can't add more";
	}
};

class noSpan : public std::exception
{
	virtual const char *what() const throw()
	{
		return "No span can be calculated, not enough numbers";
	}
};

class Span 
{
    private :
        unsigned int _n;
        std::vector<int> _data;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span &operator=(const Span& other);
        ~Span();
        void addNumber(int num);
        int shortestSpan();
        int longestSpan();
        template <typename T> void addRange(T begin, T end)
        {
            while (begin != end)
            {
                addNumber(*begin);
                begin++;
            }
        };      
};

#endif