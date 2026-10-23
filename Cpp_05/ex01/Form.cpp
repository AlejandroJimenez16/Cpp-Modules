/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 20:19:50 by alejandj          #+#    #+#             */
/*   Updated: 2026/10/24 19:16:59 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExec): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& object): _name(object._name), _signed(object._signed), _gradeToSign(object._gradeToSign), _gradeToExec(object._gradeToExec) {}

Form& Form::operator=(const Form& object)
{
	if (this != &object)
		_signed = object._signed;

	return (*this);
}

Form::~Form() {}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExec() const
{
	return (_gradeToExec);
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream& operator<<(std::ostream& out, const Form& object)
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
