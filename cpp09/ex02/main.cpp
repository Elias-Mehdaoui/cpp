#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <ctime>
#include <stdlib.h>

template <typename Container>
int parse(char **argv, Container *numbers)
{
    for (int i = 1; argv[i]; ++i)
    {
        std::istringstream ss(argv[i]);
        std::string token;

        while(ss >> token)
        {
            char *endptr;
            unsigned long num;

            if (token[0] == '-')
            {
                std::cout << "Error bad arg : " << token << std::endl;
                return 1;
            }
            
            num = strtoul(token.c_str(), &endptr, 10);

            if (*endptr || num > 2147483647)
            {
                std::cout << "Error bad arg : " << token << std::endl;
                return 2;
            }

            (*numbers).push_back(num);
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Error : usage \"./PmergeMe 1 2 etc...\"" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    if (parse(argv, &vec) || parse(argv, &deq))
        return 1;

    std::cout << "Before: ";
    for (std::size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i + 1 < vec.size())
            std::cout << " ";
    }
    std::cout << std::endl;

    PmergeMe merger(vec, deq);

    std::clock_t startVec = std::clock();
    std::vector<int> res_vec = merger.fjVec();
    std::clock_t endVec = std::clock();

    std::clock_t startDeq = std::clock();
    std::deque<int> res_deq = merger.fjDeq();
    std::clock_t endDeq = std::clock();

    std::cout << "After:  ";
    for (std::size_t i = 0; i < res_vec.size(); ++i)
    {
        std::cout << res_vec[i];
        if (i + 1 < res_vec.size())
            std::cout << " ";
    }
    std::cout << std::endl;
    double timeVecUs = static_cast<double>(endVec - startVec) * 1e6 / CLOCKS_PER_SEC;
    double timeDeqUs = static_cast<double>(endDeq - startDeq) * 1e6 / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << timeVecUs << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << timeDeqUs << " us" << std::endl;

    return 0;
}