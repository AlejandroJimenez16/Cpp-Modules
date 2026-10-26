/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:48:22 by alejandj          #+#    #+#             */
/*   Updated: 2026/10/26 19:23:25 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(time(NULL));

	std::cout << "======================" << std::endl;
	std::cout << " Test 1: (SUCCESS)" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "Signing and execution succeed: grade 1 meets all grade requirements" << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat a("A", 1);

		std::cout << a << std::endl;

		ShrubberyCreationForm formShrubbery("Tree");
		RobotomyRequestForm formRobotomy("Marvin");
		PresidentialPardonForm formPresidential("Marvin");

		std::cout << formShrubbery;
		std::cout << formRobotomy;
		std::cout << formPresidential << std::endl;

		std::cout << "ShrubberyCreationForm:" << std::endl;
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
		std::cerr << e.what() << '\n';
	}

	std::cout << "======================" << std::endl;
	std::cout << " Test 2: (EXCEPTION)" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "Execution fails: grade 150 is too low to execute signed forms" << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat b("B", 1);
		Bureaucrat c("C", 150);

		std::cout << b;
		std::cout << c << std::endl;

		ShrubberyCreationForm formShrubbery("Tree");
		RobotomyRequestForm formRobotomy("Marvin");
		PresidentialPardonForm formPresidential("Marvin");

		std::cout << formShrubbery;
		std::cout << formRobotomy;
		std::cout << formPresidential << std::endl;

		std::cout << "ShrubberyCreationForm:" << std::endl;
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
		std::cerr << e.what() << '\n';
	}

	std::cout << "======================" << std::endl;
	std::cout << " Test 3: (EXCEPTION)" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "Signing and execution fail: grade 150 is too low to sign the forms, so they cannot be executed" << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat d("D", 150);

		std::cout << d << std::endl;

		ShrubberyCreationForm formShrubbery("Tree");
		RobotomyRequestForm formRobotomy("Marvin");
		PresidentialPardonForm formPresidential("Marvin");

		std::cout << formShrubbery;
		std::cout << formRobotomy;
		std::cout << formPresidential << std::endl;

		std::cout << "ShrubberyCreationForm:" << std::endl;
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
		std::cerr << e.what() << '\n';
	}

	return (0);
}
