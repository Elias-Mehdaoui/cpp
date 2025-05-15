#include "Contact.hpp"

Contact::Contact(string firstname, string lastname, string nickname, string number, string secret) {
    
    this->firstname = firstname;
    this->lastname = lastname;
    this->nickname = nickname;
    this->number = number;
    this->secret = secret;
}

Contact::~Contact() {

}

