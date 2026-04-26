#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(std::vector<int> numbers)
{
    _vecNum = numbers;
}

PmergeMe::PmergeMe(std::deque<int> numbers)
{
    _deqNum = numbers;
}

PmergeMe::PmergeMe(std::vector<int> vecNum, std::deque<int> deqNum) : _vecNum(vecNum), _deqNum(deqNum)
{
}

PmergeMe::PmergeMe(const PmergeMe &other) : _vecNum(other._vecNum), _deqNum(other._deqNum) 
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_vecNum = other._vecNum;
		_deqNum = other._deqNum;
	}
	return *this;
}

std::vector<int> PmergeMe::fjVec()
{
    if (_vecNum.size() < 2)
        return _vecNum;
    
    int rest = -1;
    if (_vecNum.size() % 2 != 0)
    {
        rest = _vecNum.back();
        _vecNum.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;

    for (size_t i = 0; i < _vecNum.size() - 1; i += 2)
    {
        if (_vecNum[i] > _vecNum[i + 1])
            pairs.push_back(std::make_pair(_vecNum[i], _vecNum[i + 1]));
        else
            pairs.push_back(std::make_pair(_vecNum[i + 1], _vecNum[i]));
    }

    std::sort(pairs.begin(), pairs.end());

    std::vector<int> mainChain;
    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    mainChain.insert(mainChain.begin(), pend[0]);

    size_t prev_j = 1;
    size_t curr_j = 3;
    size_t j_minus_2 = 1;
    size_t i = 0;
    std::vector<int>::iterator pos;

    while (prev_j < pend.size())
    {
        curr_j = prev_j + 2 * j_minus_2;
        i = curr_j - 1;
        if (curr_j - 1 > pend.size() - 1)
            i = pend.size() - 1;
        
        while (i > prev_j - 1)
        {
            pos = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
            mainChain.insert(pos, pend[i]);
            i--;
        }
        
        j_minus_2 = prev_j;
        prev_j = curr_j;
    }

    if (rest != -1)
    {
        pos = std::lower_bound(mainChain.begin(), mainChain.end(), rest);
        mainChain.insert(pos, rest);
    }

    return mainChain;
} 

std::deque<int> PmergeMe::fjDeq()
{
    if (_deqNum.size() < 2)
        return _deqNum;

    int rest = -1;
    if (_deqNum.size() % 2 != 0)
    {
        rest = _deqNum.back();
        _deqNum.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;

    for (size_t i = 0; i < _deqNum.size() - 1; i += 2)
    {
        if (_deqNum[i] > _deqNum[i + 1])
            pairs.push_back(std::make_pair(_deqNum[i], _deqNum[i + 1]));
        else
            pairs.push_back(std::make_pair(_deqNum[i + 1], _deqNum[i]));
    }

    std::sort(pairs.begin(), pairs.end());

    std::deque<int> mainChain;
    std::deque<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    mainChain.insert(mainChain.begin(), pend[0]);

    size_t prev_j = 1;
    size_t curr_j = 3;
    size_t j_minus_2 = 1;
    size_t i;
    std::deque<int>::iterator pos;

    while (prev_j < pend.size())
    {
        curr_j = prev_j + 2 * j_minus_2;
        i = curr_j - 1;
        if (curr_j - 1 > pend.size() - 1)
            i = pend.size() - 1;
        
        while (i > prev_j - 1)
        {
            pos = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
            mainChain.insert(pos, pend[i]);
            i--;
        }
        
        j_minus_2 = prev_j;
        prev_j = curr_j;
    }

    if (rest != -1)
    {
        pos = std::lower_bound(mainChain.begin(), mainChain.end(), rest);
        mainChain.insert(pos, rest);
    }

    return mainChain;
} 