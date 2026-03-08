#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>


class RPN 
{
    private:
        std::stack<int> _stack;

    public:
        RPN();
        RPN(const RPN& other);
        RPN &operator=(const RPN& other);
        ~RPN();
        int calculate(std::string arg);
};