#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;
    if (argc > 1)
    {
        std::locale loc;
        while(i < argc  )
        {
            while(argv[i][j])
            {
                std::cout << std::toupper(argv[i][j], loc);
                j++;    
            }
            i++;
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; 
    std::cout << std::endl;
    return (0);
}