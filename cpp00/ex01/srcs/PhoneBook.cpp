#include <iostream>
#include <iomanip>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

std::string truncate_field(const std::string& str) 
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

Phonebook::Phonebook(): _nb_contact(0), _older(0)
{
    return ;
}

Phonebook::~Phonebook() {
    return ;
}

int    Phonebook::add_contact()
{
    Contact new_contact;
    if (new_contact.init_contact())
        return (1);
    if (this->_nb_contact == 8)
        _contact_list[this->_older] = new_contact;
    else
        _contact_list[this->_nb_contact] = new_contact;
    this->_nb_contact++;
    return (0);
}

void Phonebook::display_list()
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < 8; i++) {
        std::cout << std::setw(10) << i << "|";
        if (i < this->_nb_contact) 
        {
            std::cout << std::setw(10) << truncate_field(this->_contact_list[i].getFirstname()) << "|"
                      << std::setw(10) << truncate_field(this->_contact_list[i].getLastname()) << "|"
                      << std::setw(10) << truncate_field(this->_contact_list[i].getNickname());
        }
        std::cout << std::endl;
    }
}
void Phonebook::display_info(int index)
{
        std::cout << "Firstname : " << this->_contact_list[index].getFirstname() << std::endl;
        std::cout << "Lastname : " << this->_contact_list[index].getLastname() << std::endl;
        std::cout << "Nickname : " << this->_contact_list[index].getNickname() << std::endl;
        std::cout << "Number : " << this->_contact_list[index].getNumber() << std::endl;
        std::cout << "Darkest secret : " << this->_contact_list[index].getSecret() << std::endl;
}