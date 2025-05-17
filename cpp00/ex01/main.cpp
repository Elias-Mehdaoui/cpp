#include "includes/PhoneBook.hpp"
#include <iostream>
#include <string>

int search_menu(Phonebook phonebook)
{
    int index;
    phonebook.display_list();
    std::cout << "Index :" << std::endl;
    if (!(std::cin >> index))
        return (1);
    if (index < 0 || index >= phonebook.getNb_contact())
        std::cout << "Index out of range" << std::endl;
    else
        phonebook.display_info(index);
    return (0);
}

void display_menu(Phonebook phonebook)
{
    int exit;
    std::string command;

    exit = 0;
    while(!exit)
    {
        std::cout << "Enter a command : ADD, SEARCH, EXIT" << std::endl;
        if (!(std::cin >> command))
            break;
        if (command == "ADD")
            if (phonebook.add_contact())
                break;
        if (command == "SEARCH")
            if (search_menu(phonebook))
                break;
        if (command == "EXIT")
            exit = 1;
    }
}

int main(void) 
{
    Phonebook phonebook;
    display_menu(phonebook);
    return (0);
}

