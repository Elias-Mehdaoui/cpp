#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <exception> 
#include <limits.h> 
#include <float.h>
#include <cmath>
#include <string>
#include <stdexcept>


class ScalarConverter {
private:
    ScalarConverter();
public:
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    static void convert(std::string input);
};