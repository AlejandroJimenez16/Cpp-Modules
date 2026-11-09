/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 19:10:48 by alejandj          #+#    #+#             */
/*   Updated: 2026/11/09 13:08:13 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& object)
{
	*this = object;
}

Intern& Intern::operator=(const Intern& object)
{
	(void)object;
	return (*this);
}

Intern::~Intern() {}

AForm* Intern::createShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	AForm* (Intern::*formTypes[3]) (const std::string&) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

    std::string supportedNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == supportedNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formTypes[i])(target);
		}
	}

	std::cerr << "Intern: unknown form name \"" << formName << "\"" << std::endl;
	return (NULL);
}
