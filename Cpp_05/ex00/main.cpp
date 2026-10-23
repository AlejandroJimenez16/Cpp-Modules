/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:41:50 by alejandj          #+#    #+#             */
/*   Updated: 2026/10/23 20:56:47 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
		std::cerr << e.what() << '\n';
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
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "======================" << std::endl;
	std::cout << " Test 1: (SUCCESS)" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "Grade 42: increment and decrement work as expected" << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat a("A", 42);

		std::cout << a << std::endl;
		tryIncrement(a);
		tryDecrement(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "======================" << std::endl;
	std::cout << " Test 2: (EXCEPTION)" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "Grade 1: increment should throw an exception" << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat b("B", 1);

		std::cout << b << std::endl;
		tryIncrement(b);
		tryDecrement(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "======================" << std::endl;
	std::cout << " Test 3: (EXCEPTION)" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "Grade 150: decrement should throw an exception" << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat c("C", 150);

		std::cout << c << std::endl;
		tryDecrement(c);
		tryIncrement(c);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "======================" << std::endl;
	std::cout << " Test 4: (EXCEPTION)" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "Invalid grades: 0 and 151" << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat x("X", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat x("X", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
