/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 20:31:03 by alejandj          #+#    #+#             */
/*   Updated: 2026/10/23 21:25:52 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "======================" << std::endl;
	std::cout << " Test 1: (SUCCESS)" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "Signing succeeds: bureaucrat meets the grade requirement" << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat a("A", 42);
		Form formA("formA", 50, 150);

		std::cout << a << std::endl;
		a.signForm(formA);
		std::cout << std::endl;

		std::cout << formA << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "======================" << std::endl;
	std::cout << " Test 2: (EXCEPTION)" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "Signing fails: bureaucrat does not meet the grade requirement" << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat b("B", 100);
		Form formB("formB", 50, 150);

		std::cout << b << std::endl;
		b.signForm(formB);
		std::cout << std::endl;

		std::cout << formB << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "======================" << std::endl;
	std::cout << " Test 3: (EXCEPTION)" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "Invalid grades: 0 and 151" << std::endl;

	std::cout << std::endl;

	std::cout << "Invalid signing grade:" << std::endl;
	
	try
	{
		Form x("X", 0, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form x("X", 151, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nInvalid execution grade:" << std::endl;
	
	try
	{
		Form x("X", 42, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form x("X", 42, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
