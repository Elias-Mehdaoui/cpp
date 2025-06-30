#include <iostream>
#include <string>
#include <stdint.h>

struct Data 
{
    int id;
    std::string str;
};

class Serializer 
{
    private :
        Serializer();
    public :
        ~Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};