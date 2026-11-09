/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 20:38:09 by alejandj          #+#    #+#             */
/*   Updated: 2026/11/09 13:31:04 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define PURPLE "\033[1;35m"
#define RESET "\033[0m"

int main(void)
{
	std::cout << PURPLE << "[INFO] Supported form names:" << RESET << std::endl;
	std::cout << PURPLE << "       - shrubbery creation" << RESET << std::endl;
	std::cout << PURPLE << "       - robotomy request" << RESET << std::endl;
	std::cout << PURPLE << "       - presidential pardon" << RESET << std::endl;

	std::cout << std::endl;

	Intern intern;

	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << " Test 1: (SUCCESS)" << RESET << std::endl;
	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << "Form creation succeeds: intern recognizes the form types" << RESET << std::endl;

	std::cout << std::endl;

	AForm* shrubbery = intern.makeForm("shrubbery creation", "Marvin");
	AForm* robotomy = intern.makeForm("robotomy request", "Marvin");
	AForm* presidential = intern.makeForm("presidential pardon", "Marvin");

	std::cout << std::endl;

	if (!shrubbery || !robotomy || !presidential)
	{
		std::cerr << RED << "ERROR: intern failed to create a form" << RESET << std::endl;

		delete shrubbery;
		delete robotomy;
		delete presidential;

		return (1);
	}

	std::cout << *shrubbery << std::endl;
	std::cout << *robotomy << std::endl;
	std::cout << *presidential << std::endl;

	std::cout << std::endl;

	delete shrubbery;
	delete robotomy;
	delete presidential;

	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << " Test 2: (FAILURE)" << RESET << std::endl;
	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << "Form creation fails: intern does not recognize the form type" << RESET << std::endl;

	std::cout << std::endl;

	intern.makeForm("testForm", "Marvin");

	return (0);
}
