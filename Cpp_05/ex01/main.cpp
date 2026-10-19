/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 20:31:03 by alejandj          #+#    #+#             */
/*   Updated: 2026/10/19 22:14:51 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat a("A", 42);
	Bureaucrat b("B", 100);
	
	Form formA("formA", 50, 150);
	Form formB("formB", 50, 150);
	
	std::cout << "======================" << std::endl;
	std::cout << " Test 1: (OK)" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "Sign the form correctly" << std::endl;

	std::cout << std::endl;

	std::cout << a << std::endl;
	a.signForm(formA);
	std::cout << std::endl;

	std::cout << formA << std::endl;

	std::cout << "======================" << std::endl;
	std::cout << " Test 2: (ERROR)" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "Sign fails: bureaucrat grade does not reach the required grade" << std::endl;

	std::cout << std::endl;

	std::cout << b << std::endl;
	b.signForm(formB);
	std::cout << std::endl;

	std::cout << formB << std::endl;

	std::cout << "======================" << std::endl;
	std::cout << " Test 3: (ERROR)" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "Invalid constructors: grades 0 and 151" << std::endl;

	std::cout << std::endl;

	try
	{
		Form x("X", 0, 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form x("X", 151, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
