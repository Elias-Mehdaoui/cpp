#ifndef MUTANTSTACK_HPP_
#define MUTANTSTACK_HPP_

#include <stack>
#include <iostream>

template <typename T>

class MutantStack: public std::stack<T> 
{
    public:
        MutantStack(){};
        MutantStack(const MutantStack& other) : std::stack<T>(other) {};
        MutantStack& operator=(const MutantStack& other)
        {
            std::stack<T>::operator=(other);
            return *this;
        };
		~MutantStack(){};
		typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        iterator begin(void){return this -> c.begin();}
        iterator end(void){return this -> c.end();}
        const_iterator cbegin(void){return this -> c.begin();}
        const_iterator cend(void){return this -> c.end();}
};

#endif