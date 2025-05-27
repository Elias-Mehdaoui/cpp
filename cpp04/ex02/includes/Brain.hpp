#ifndef BRAIN_HPP_
#define BRAIN_HPP_

#include <string>
#include <iostream>

class Brain
{
    protected :
        std::string _ideas[100];
    
    public :
        Brain();
        Brain(const Brain& other);
        virtual ~Brain();
        Brain& operator=(const Brain& other);

        void setIdea(int index, std::string idea);
        std::string getIdea(int index);
};

#endif