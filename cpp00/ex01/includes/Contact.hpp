#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>

class Contact {
    private :
        std::string _firstname;
        std::string _lastname;
        std::string _nickname;
        std::string _number;
        std::string _secret;
    
    public :
        Contact();
        ~Contact();

        int    init_contact();

        std::string  getFirstname()
        {
            return (this->_firstname);
        }
        std::string  getLastname()
        {
            return (this->_lastname);
        }
        std::string  getNickname()
        {
            return (this->_nickname);
        }
        std::string  getNumber()
        {
            return (this->_number);
        }
        std::string  getSecret()
        {
            return (this->_secret);
        }
};

#endif