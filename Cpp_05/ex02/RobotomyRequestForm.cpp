/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 17:20:20 by alejandj          #+#    #+#             */
/*   Updated: 2026/10/26 19:21:47 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& object): AForm(object), _target(object._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& object)
{
	if (this != &object)
	{
		AForm::operator=(object);
		_target = object._target;
	}

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!this->getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();

	std::cout << "BRRRRRRRRRRRRRRRRRRRRRRRR..." << std::endl;

	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy on " << _target << " failed" << std::endl;
}
