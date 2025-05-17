#include <fstream>
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 4 || !*argv[2])
    {
        std::cout << "You must provide a filename s1 and s2" << std::endl;
        return (0);
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    std::ifstream inputFile(filename.c_str());
    if (!inputFile)
    {
        std::cout << "Failed to open " << filename << std::endl;
        return (0);
    }
    
    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile)
    {
        std::cout << "Failed to open/create " << filename + ".replace" << std::endl;
        return (0);
    }

    std::string line;
    std::string res;
    while (std::getline(inputFile, line)) 
    {
        size_t found = 0;
        size_t pos = 0;
        while ((found = line.find(s1, pos)) != std::string::npos)
        {
            if (found != std::string::npos)
            {
                res += line.substr(pos , found - pos);
                res += s2;
                pos = found + s1.length();
            }
        }
        res += line.substr(pos);
        outputFile << res;
    }
}
