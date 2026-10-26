/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 13:58:33 by alejandj          #+#    #+#             */
/*   Updated: 2026/10/25 16:55:59 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& object): AForm(object), _target(object._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& object)
{
    if (this != &object)
    {
        AForm::operator=(object);
        _target = object._target;
    }

    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (!this->getSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExec())
        throw GradeTooLowException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
