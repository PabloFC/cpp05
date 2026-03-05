/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:22:38 by pafuente          #+#    #+#             */
/*   Updated: 2026/03/05 12:22:38 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* ================= CONSTRUCTORS ================= */

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name), _grade(grade)
{
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade)
{
}

/* ================= DESTRUCTOR ================= */

Bureaucrat::~Bureaucrat()
{
}

/* ================= OPERATOR= ================= */

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        _grade = other._grade; // _name es const
    return *this;
}

/* ================= GETTERS ================= */

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

/* ================= GRADE CONTROL ================= */

void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

/* ================= SIGN FORM ================= */

void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << _name << " couldn’t sign "
                  << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

/* ================= EXECUTE FORM ================= */

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << _name << " couldn’t execute "
                  << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

/* ================= EXCEPTIONS ================= */

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade too low";
}

/* ================= OPERATOR << ================= */

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
    out << b.getName()
        << ", bureaucrat grade "
        << b.getGrade() << ".";
    return out;
}