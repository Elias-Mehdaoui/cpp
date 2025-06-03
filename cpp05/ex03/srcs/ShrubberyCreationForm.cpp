#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), _target(NULL)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        *this = other;
    return (*this);
}

bool ShrubberyCreationForm::action(const Bureaucrat& executor) const
{
    try 
    {
        this->execute(executor);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error : " << e.what() << std::endl;
        return (0);
    }


    std::ofstream outputFile((_target + "_shrubbery").c_str());
    if (!outputFile)
    {
        std::cout << "Failed to open/create " << _target << "_shrubbery" << std::endl;
        return (0);
    }

    outputFile << "\n\n";
    for (int i = 0; i < 3; i++)
    {
        outputFile << "		                  # #### ####\n";
        outputFile << "		                ### \\/#|### |/####\n";
        outputFile << "		               ## \\/#/ \\||/##/_/##/_#\n";
        outputFile << "		             ###  \\/###|/ \\/ # ###\n";
        outputFile << "		           ##_\\_\\#\\_\\## | #/###_/_####\n";
        outputFile << "		          ## #### # \\ #| /  #### ##/##\n";
        outputFile << "		           __#_--###`  |{,###---###-~\n";
        outputFile << "		                     \\ }{\n";
        outputFile << "		                      }}{\n";
        outputFile << "		                      }}{\n";
        outputFile << "		                      {{}\n";
        outputFile << "		                  # #### ####" << std::endl << std::endl << std::endl;
    }

    std::cout << "Shrubbery created in " << _target << "_shrubbery" << std::endl;
    return (1);
}


