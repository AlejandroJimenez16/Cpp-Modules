/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 11:49:22 by alejandj          #+#    #+#             */
/*   Updated: 2026/10/25 17:15:42 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& object): AForm(object), _target(object._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& object)
{
	if (this != &object)
	{
		AForm::operator=(object);
		_target = object._target;
	}

	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!this->getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();

	std::string fileName = _target + "_shrubbery";
	std::ofstream file(fileName.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: Could not create file '" << fileName << std::endl;
		return ;
	}

	file << "        /\\"		<< std::endl;
    file << "       /  \\"		<< std::endl;
    file << "      /    \\"		<< std::endl;
    file << "     /______\\"	<< std::endl;
    file << "      /    \\"		<< std::endl;
    file << "     /      \\"	<< std::endl;
    file << "    /________\\"	<< std::endl;
    file << "     /      \\"	<< std::endl;
    file << "    /        \\"	<< std::endl;
    file << "   /__________\\"	<< std::endl;
    file << "       ||||"		<< std::endl;
    file << "       ||||"		<< std::endl;
}
