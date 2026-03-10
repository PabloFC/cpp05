#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &copy);
    Intern &operator=(const Intern &copy);
    ~Intern();

    AForm *makeForm(const std::string &name, const std::string &target);
};

#endif