#include <iostream>
#include <Array.hpp>

int main()
{
    Array<int> test(10);

    for (int i = 0; i < 10; i++)
        test[i] = i;

    Array<int> test2(test);
    test2[0] = 10;
    try 
    {
        for (int i = 0; i < 10; i++)
        {
            std::cout << "test2[i] = " << test2[i] << std::endl;
            std::cout << "test[i] = " << test[i] << std::endl;
        }

        test2 = test;

        for (int i = 0; i < 11; i++)
        {
            std::cout << "-------------------------------" << std::endl;
            std::cout << "test2[i] = " << test2[i] << std::endl;
            std::cout << "test[i] = " << test[i] << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
