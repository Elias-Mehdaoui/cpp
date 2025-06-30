#include <Serializer.hpp>
#include <cassert>

int main()
{
    Data* original = new Data;
    original->id = 1;
    original->str = "oui";
    uintptr_t serialized = Serializer::serialize(original);
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "original pointer " << original << std::endl; 
    std::cout << "deserialized pointer " << deserialized << std::endl; 
}