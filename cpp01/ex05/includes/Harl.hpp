#ifndef HARL_HPP_
#define HARL_HPP_
#include <iostream>
#include <string>

class Harl 
{
    private :
        void debug();
        void info();
        void warning();
        void error();
    
    public :
        Harl();
        ~Harl();
        void complain(std::string level);
};

#endif