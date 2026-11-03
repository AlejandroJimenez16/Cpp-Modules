/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:41:50 by alejandj          #+#    #+#             */
/*   Updated: 2026/11/03 20:40:39 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

void tryIncrement(Bureaucrat& b)
{
	std::cout << "Increment:" << std::endl;
	
	try
	{
		b.incrementGrade();
		std::cout << "Grade: " << b.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;
}

void tryDecrement(Bureaucrat& b)
{
	std::cout << "Decrement:" << std::endl;
	
	try
	{
		b.decrementGrade();
		std::cout << "Grade: " << b.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	std::cout << std::endl;
}

int main(void)
{
	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << " Test 1: (SUCCESS)" << RESET << std::endl;
	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << "Grade 42: increment and decrement work as expected" << RESET << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat a("A", 42);

		std::cout << a << std::endl;
		std::cout << std::endl;

		tryIncrement(a);
		tryDecrement(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << " Test 2: (EXCEPTION)" << RESET << std::endl;
	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << "Grade 1: increment should throw an exception" << RESET << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat b("B", 1);

		std::cout << b << std::endl;
		std::cout << std::endl;

		tryIncrement(b);
		tryDecrement(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << " Test 3: (EXCEPTION)" << RESET << std::endl;
	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << "Grade 150: decrement should throw an exception" << RESET << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat c("C", 150);

		std::cout << c << std::endl;
		std::cout << std::endl;

		tryDecrement(c);
		tryIncrement(c);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << " Test 4: (EXCEPTION)" << RESET << std::endl;
	std::cout << GREEN << "======================" << RESET << std::endl;
	std::cout << GREEN << "Invalid grades: 0 and 151" << RESET << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat x("X", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		Bureaucrat x("X", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return (0);
}
