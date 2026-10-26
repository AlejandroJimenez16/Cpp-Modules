/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 20:19:50 by alejandj          #+#    #+#             */
/*   Updated: 2026/10/26 19:21:34 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("Default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& object): _name(object._name), _signed(object._signed), _gradeToSign(object._gradeToSign), _gradeToExec(object._gradeToExec) {}

AForm& AForm::operator=(const AForm& object)
{
	if (this != &object)
		_signed = object._signed;

	return (*this);
}

AForm::~AForm() {}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExec() const
{
	return (_gradeToExec);
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("To execute the form, it must be signed");
}

std::ostream& operator<<(std::ostream& out, const AForm& object)
{
	out << "Form " << object.getName();

	if (object.getSigned())
		out << " is signed, ";
	else
		out << " is unsigned, ";

	out << "the grade required to sign is " << object.getGradeToSign()
		<< " and the grade required to execute is " << object.getGradeToExec() << std::endl;

	return (out);
}
