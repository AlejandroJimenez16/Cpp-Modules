/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:48:22 by alejandj          #+#    #+#             */
/*   Updated: 2026/11/03 20:36:51 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

int main(void)
{
	std::srand(std::time(NULL));

	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << " Test 1: (SUCCESS)" << RESET << std::endl;
	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << "Signing and execution succeed: grade 1 meets all grade requirements" << RESET << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat a("A", 1);

		std::cout << a << std::endl;
		std::cout << std::endl;

		ShrubberyCreationForm formShrubbery("Tree");
		RobotomyRequestForm formRobotomy("Marvin");
		PresidentialPardonForm formPresidential("Marvin");

		std::cout << formShrubbery << std::endl;
		std::cout << formRobotomy << std::endl;
		std::cout << formPresidential << std::endl;

		std::cout << "\nShrubberyCreationForm:" << std::endl;
		a.signForm(formShrubbery);
		a.executeForm(formShrubbery);

		std::cout << "\nRobotomyRequestForm:" << std::endl;
		a.signForm(formRobotomy);
		a.executeForm(formRobotomy);

		std::cout << "\nPresidentialPardonForm:" << std::endl;
		a.signForm(formPresidential);
		a.executeForm(formPresidential);

		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << " Test 2: (EXCEPTION)" << RESET << std::endl;
	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << "Execution fails: grade 150 is too low to execute signed forms" << RESET << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat b("B", 1);
		Bureaucrat c("C", 150);

		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << std::endl;

		ShrubberyCreationForm formShrubbery("Tree");
		RobotomyRequestForm formRobotomy("Marvin");
		PresidentialPardonForm formPresidential("Marvin");

		std::cout << formShrubbery << std::endl;
		std::cout << formRobotomy << std::endl;
		std::cout << formPresidential << std::endl;

		std::cout << "\nShrubberyCreationForm:" << std::endl;
		b.signForm(formShrubbery);
		c.executeForm(formShrubbery);

		std::cout << "\nRobotomyRequestForm:" << std::endl;
		b.signForm(formRobotomy);
		c.executeForm(formRobotomy);

		std::cout << "\nPresidentialPardonForm:" << std::endl;
		b.signForm(formPresidential);
		c.executeForm(formPresidential);

		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << " Test 3: (EXCEPTION)" << RESET << std::endl;
	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << "Signing and execution fail: grade 150 is too low to sign the forms, so they cannot be executed" << RESET << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat d("D", 150);

		std::cout << d << std::endl;
		std::cout << std::endl;

		ShrubberyCreationForm formShrubbery("Tree");
		RobotomyRequestForm formRobotomy("Marvin");
		PresidentialPardonForm formPresidential("Marvin");

		std::cout << formShrubbery << std::endl;
		std::cout << formRobotomy << std::endl;
		std::cout << formPresidential << std::endl;

		std::cout << "\nShrubberyCreationForm:" << std::endl;
		d.signForm(formShrubbery);
		d.executeForm(formShrubbery);

		std::cout << "\nRobotomyRequestForm:" << std::endl;
		d.signForm(formRobotomy);
		d.executeForm(formRobotomy);

		std::cout << "\nPresidentialPardonForm:" << std::endl;
		d.signForm(formPresidential);
		d.executeForm(formPresidential);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return (0);
}
