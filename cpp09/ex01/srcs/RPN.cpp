#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN& other)
{
    (void)other;
}

RPN& RPN::operator=(const RPN& other)
{
    (void)other;
    return *this;
}

RPN::~RPN()
{

}

int RPN::calculate(std::string arg)
{
    std::stringstream ss(arg);
    std::string token;
    
    while (ss >> token)
    {
        if (isdigit(token[0]))
            _stack.push(atoi(token.c_str()));
        else if (_stack.size() <= 1)
            throw std::runtime_error("Error: Wrong args");
        else
        {
            int num1, num2;

            num2 = _stack.top();
            _stack.pop();
            num1 = _stack.top();
            _stack.pop();

            if (token == "+")
                _stack.push(num1 + num2);
            else if (token == "-")
                _stack.push(num1 - num2);
            else if (token == "*")
                _stack.push(num1 * num2);
            else if (token == "/")
            {
                if (num2 == 0)
                    throw std::runtime_error("Error: Div by zero");
                _stack.push(num1 / num2);  
            }
            else
                throw std::runtime_error("Error: Wrong args");
        }            
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error: Wrong args");
    return (_stack.top());
}