/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:29:02 by alejandj          #+#    #+#             */
/*   Updated: 2026/10/17 23:38:05 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& object): _name(object._name), _grade(object._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& object)
{
	if (this != &object)
		_grade = object._grade;

	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();

	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();

	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& object)
{
	out << object.getName() << ", bureaucrat grade " << object.getGrade() << std::endl;
	return (out);
}
