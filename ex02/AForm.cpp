/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:22:19 by pafuente          #+#    #+#             */
/*   Updated: 2026/03/05 12:22:21 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {}

AForm::AForm(const std::string& name, int sign, int exec)
    : _name(name), _isSigned(false), _gradeToSign(sign), _gradeToExec(exec)
{
    if (sign < 1 || exec < 1)
        throw GradeTooHighException();
    if (sign > 150 || exec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign),
      _gradeToExec(other._gradeToExec) {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExec() const { return _gradeToExec; }

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "form not signed";
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
    out << f.getName()
        << ", sign grade " << f.getGradeToSign()
        << ", exec grade " << f.getGradeToExec()
        << ", signed: " << f.getIsSigned();
    return out;
}