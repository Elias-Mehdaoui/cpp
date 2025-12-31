#include "Span.hpp"

int main()
{

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span sp2 = Span(15000);
    std::vector<int> numbers;
    
    for (int i = 0; i < 15000; i++) {
        numbers.push_back(i);
    }
    
    sp2.addRange(numbers.begin(), numbers.end());
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

    return 0;
}
