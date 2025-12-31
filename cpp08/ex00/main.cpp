#include <vector>
#include <iostream>
#include "easyfind.hpp"

int main()
{
    std::vector<int>::iterator it;
    std::vector<int> container;

    for (int i = 0; i < 6; i++)
        container.push_back(i);

    it = easyfind(container, 2);
    std::cout << "value to find : 2 | it = " << (*it) << std::endl;

    it = easyfind(container, 7);
    if (it == container.end())
        std::cout << "Value not found" << std::endl;
    std::cout << "it = "<< (*it) << " | " << "container.end() = " << (*container.end()) << std::endl;
}