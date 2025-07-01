#include <iostream>
#include <string>
#include "iter.hpp"

// Assuming iter is implemented elsewhere (e.g., in a header)
template <typename T, typename Func>
void iter(T* array, size_t length, Func func) {
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

// Test functions
template <typename T>
void print(const T& x) {
    std::cout << x << " ";
}

void increment(int& x) {
    x++;
}

void capitalize(std::string& s) {
    if (!s.empty()) s[0] = toupper(s[0]);
}

int main() {
    // Test 1: int array (modify)
    int nums[] = {1, 2, 3};
    size_t len = sizeof(nums)/sizeof(nums[0]);

    std::cout << "Before: ";
    iter(nums, len, print<int>);
    std::cout << "\nAfter:  ";
    iter(nums, len, increment);
    iter(nums, len, print<int>);
    std::cout << "\n\n";

    // Test 2: const array (read-only)
    const int const_nums[] = {10, 20, 30};
    std::cout << "Const:  ";
    iter(const_nums, len, print<int>);
    std::cout << "\n\n";

    // Test 3: strings (modify)
    std::string words[] = {"apple", "banana", "cherry"};
    len = sizeof(words)/sizeof(words[0]);

    std::cout << "Before: ";
    iter(words, len, print<std::string>);
    std::cout << "\nAfter:  ";
    iter(words, len, capitalize);
    iter(words, len, print<std::string>);
    std::cout << "\n";

    return 0;
}