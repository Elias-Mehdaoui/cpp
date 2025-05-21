#include "../includes/Harl.hpp"

Harl::Harl()
{
    return ;
}

Harl::~Harl()
{
    return ;
}

void Harl::debug()
{
    std::cout << "Debug: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void Harl::info()
{
    std::cout << "Info: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you don’t put enough bacon in, I will not give you my money." << std::endl;
}
void Harl::warning()
{
    std::cout << "Warning: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error()
{
    std::cout << "Error: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    struct Harlcomplaints {
        std::string level;
        void (Harl::*function)(void);
    };

    Harlcomplaints complaints[] = {
        {"DEBUG", &Harl::debug},
        {"INFO", &Harl::info},
        {"WARNING", &Harl::warning},
        {"ERROR", &Harl::error}
    };

    for (int i = 0; i < 4; i++)
    {
        if (level == complaints[i].level)
        {
            (this->*complaints[i].function)();
            return ;
        }
    }
    std::cout << "* Complaining about something irrelevant *" << std::endl;
}