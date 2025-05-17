#include "Contact.hpp"
#include <iostream>

Contact::Contact(): _number("e") {
    return ;
}

Contact::~Contact() {
    return ;
}

int Contact::init_contact()
{
    std::string prompt;
    std::cout << "Please enter the contact's information" << std::endl;
    std::cout << "Firstname :" << std::endl;
    if (!(std::cin >> this->_firstname))
        return (1);
    std::cout << "Lastname :" << std::endl;
    if (!(std::cin >> this->_lastname))
        return (1);
    std::cout << "Nickname :" << std::endl;
    if (!(std::cin >> this->_nickname))
        return (1);
    std::cout << "Number :" << std::endl;
    while (this->_number == "e")
    {
        if (!(std::cin >> prompt))
            return (1);
        for (unsigned long i = 0; prompt[i]; i++)
        {
            if (!std::isdigit(prompt[i]))
            {
                std::cout << "Please enter digits only" << std::endl;
                break;
            }
            if (i == prompt.length() - 1)
                this->_number = prompt;
        }
    }
    std::cout << "Darkest secret :" << std::endl;
    if (!(std::cin >> this->_secret))
        return (1);
    return (0);
}

