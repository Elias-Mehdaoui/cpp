#include <stack>
#include <iostream>

template <typename T>

class MutantStack: public std::stack<T> 
{
    public:
        MutantStack(){};
        MutantStack(const MutantStack& other){(void)other;};
        MutantStack &operator=(const MutantStack& other){(void)other;};
		~MutantStack(){};
		typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        iterator begin(void){return this -> c.begin();}
        iterator end(void){return this -> c.end();}
        const iterator cbegin(void){return this -> c.begin();}
        const iterator cend(void){return this -> c.end();}
};