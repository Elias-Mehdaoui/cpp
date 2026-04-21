#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: could not open data file" << std::endl;
        return ;
    }

    std::string line;
    std::string date;
    std::string rate;
    size_t pos;
    

    std::getline(file, line);
    while (std::getline(file, line))
    {
        pos = line.find(',');
        date = line.substr(0, pos);
        rate = line.substr(pos + 1);

        _data[date] = std::strtod(rate.c_str(), NULL);
    }
    file.close();
}

BitcoinExchange::~BitcoinExchange()
{
    _data.clear();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _data(other._data)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _data = other._data;
    return *this;
}

bool valid_date(std::string date, std::string line)
{
    if (date.size() != 10)
    {
        std::cerr << "Error: bad input excepted YYYY-MM-DD got: " << line << std::endl;
        return false;
    }
        
    if (date[4] != '-' && date[7] != '-')
    {
        std::cerr << "Error: bad input excepted YYYY-MM-DD got: " << line << std::endl;
        return false;
    }

    std::string ys = date.substr(0, 4);
    std::string ms = date.substr(5, 2);
    std::string ds = date.substr(8, 2);

    char* endptr;
    long year = std::strtol(ys.c_str(), &endptr, 10);
    long month = std::strtol(ms.c_str(), &endptr, 10);
    long day = std::strtol(ds.c_str(), &endptr, 10);

    if (endptr == ys.c_str() ||  endptr == ms.c_str() || endptr == ds.c_str())
    {
        std::cerr << "Error: bad input excepted YYYY-MM-DD got: " << line << std::endl;
        return false;
    }

    if (year < 1000)
    {
        std::cerr << "Error: bad input year must be greater than 1000 got: " << line << std::endl;
        return false;
    }

    if (day < 0 || day > 31)
    {
        std::cerr << "Error: bad input day must be between 0 and 31 got: " << line << std::endl;
        return false;
    }

    if (month < 0 || month > 12)
    {
        std::cerr << "Error: bad input month must be between 0 and 12 got: " << line << std::endl;
        return false;
    }

    return true;
}

bool valid_value(std::string value_str)
{
    char *endptr;
    double value = std::strtod(value_str.c_str(), &endptr);

    if(endptr == value_str.c_str() || *endptr != '\0')
    {
        std::cerr << "Error: bad value" << std::endl;
        return false;
    }

    if(value < 0 || value > 1000)
    {
        std::cerr << "Error: too large value" << std::endl;
        return false;
    }

    return true;
}


void BitcoinExchange::process_input(std::string filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file: " << filename << std::endl;
        return ;
    }

    std::string line;
    std::string date;
    std::string value_str;
    size_t pos;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        pos = line.find('|');
        if (pos == std::string::npos)
        {
            std::cerr << "Error: bad input expected pipe got: " << line << std::endl;
        }

        date = line.substr(0, pos - 1);
        if (!valid_date(date, line))
            continue;

        value_str = line.substr(pos + 1);
        if (!valid_value(value_str))
            continue;
        
        double value = std::strtod(value_str.c_str(), NULL);

        std::map<std::string, double>::iterator it = _data.upper_bound(date);
        if (it == _data.end())
        {
            std::cerr << "Error: no rate available for date => " << date << std::endl;
            continue;
        }
        --it;
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
    }
    file.close();
}