#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <utility>

class PmergeMe
{
    private :
        std::vector<int> _vecNum;
        std::deque<int> _deqNum;
    public :
        PmergeMe();
        PmergeMe(std::vector<int> numbers);
        PmergeMe(std::deque<int> numbers);
        PmergeMe(std::vector<int> vecNum, std::deque<int> deqNum);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        std::vector<int> fjVec(); 
        std::deque<int> fjDeq(); 
};

#endif