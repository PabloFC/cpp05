#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy)
{
    (void)copy;
}

Intern &Intern::operator=(const Intern &copy)
{
    (void)copy;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    if (name == "shrubbery creation")
    {
        std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
        return new ShrubberyCreationForm(target);
    }
    else if (name == "robotomy request")
    {
        std::cout << "Intern creates RobotomyRequestForm" << std::endl;
        return new RobotomyRequestForm(target);
    }
    else if (name == "presidential pardon")
    {
        std::cout << "Intern creates PresidentialPardonForm" << std::endl;
        return new PresidentialPardonForm(target);
    }

    std::cout << "Intern cannot create this form" << std::endl;
    return NULL;
}