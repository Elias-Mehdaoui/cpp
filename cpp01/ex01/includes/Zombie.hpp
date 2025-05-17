#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <string>
#include <iostream>


class Zombie {
    private :
        std::string _name;

    public :
        Zombie();
        ~Zombie();

        void announce();

        void setName(std::string name)
        {
            _name = name;
        }
};

#endif