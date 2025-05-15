#include <iostream>
using namespace std;

class Contact {
    private :
        string firstname;
        string lastname;
        string nickname;
        string number;
        string secret;
    
    public :
        Contact(string firstname, string lastname, string nickname, string number, string secret);
        ~Contact();

        void    setFirstname(string data)
        {
            this->firstname = data;
        }
        void    setLastname(string data)
        {
            this->lastname = data;
        }
        void    setNickname(string data)
        {
            this->nickname = data;
        }
        void    setNumber(string data)
        {
            this->number = data;
        }
        void    setSecret(string data)
        {
            this->secret = data;
        }

        string  getFirstname()
        {
            return (this->firstname);
        }
        string  getLastname()
        {
            return (this->lastname);
        }
        string  getNickname()
        {
            return (this->nickname);
        }
        string  getNumber()
        {
            return (this->number);
        }
        string  getSecret()
        {
            return (this->secret);
        }
};