/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 20:31:03 by alejandj          #+#    #+#             */
/*   Updated: 2026/11/03 20:17:21 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

int main(void)
{
	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << " Test 1: (SUCCESS)" << RESET << std::endl;
	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << "Signing succeeds: bureaucrat meets the grade requirement" << RESET << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat a("A", 42);
		Form formA("formA", 50, 150);

		std::cout << a << std::endl;
		a.signForm(formA);
		std::cout << std::endl;

		std::cout << formA << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << " Test 2: (EXCEPTION)" << RESET << std::endl;
	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << "Signing fails: bureaucrat does not meet the grade requirement" << RESET << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat b("B", 100);
		Form formB("formB", 50, 150);

		std::cout << b << std::endl;
		b.signForm(formB);
		std::cout << std::endl;

		std::cout << formB << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << " Test 3: (EXCEPTION)" << RESET << std::endl;
	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << "Invalid grades: 0 and 151" << RESET << std::endl;

	std::cout << std::endl;

	std::cout << "Invalid signing grade:" << std::endl;

	try
	{
		Form x("X", 0, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		Form x("X", 151, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << "\nInvalid execution grade:" << std::endl;

	try
	{
		Form x("X", 42, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		Form x("X", 42, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return (0);
}
