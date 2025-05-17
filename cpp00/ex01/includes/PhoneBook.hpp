#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "Contact.hpp"

class   Phonebook {
    private :
            int _nb_contact;
            int _older;
            Contact _contact_list[8];

    public :
    
    Phonebook();
    ~Phonebook();
    

    int add_contact();
    void display_list();
    void display_info(int index);

    int getNb_contact()
    {
        return (this->_nb_contact);
    }
};

#endif