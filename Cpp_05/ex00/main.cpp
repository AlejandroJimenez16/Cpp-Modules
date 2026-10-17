/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:41:50 by alejandj          #+#    #+#             */
/*   Updated: 2026/10/18 00:28:15 by alejandj         ###   ########.fr       */
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
	Bureaucrat a("A", 42);
	Bureaucrat b("B", 1);
	Bureaucrat c("C", 150);

	std::cout << "======================" << std::endl;
	std::cout << " Test 1: (OK)" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "Grade 42: increment and decrement work" << std::endl;

	std::cout << std::endl;

	std::cout << a << std::endl;
	tryIncrement(a);
	tryDecrement(a);

	std::cout << "======================" << std::endl;
	std::cout << " Test 2: (ERROR)" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "Grade 1: increment must fail (too high)" << std::endl;

	std::cout << std::endl;

	std::cout << b << std::endl;
	tryIncrement(b);
	tryDecrement(b);

	std::cout << "======================" << std::endl;
	std::cout << " Test 3: (ERROR)" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "Grade 150: decrement must fail (too low)" << std::endl;

	std::cout << std::endl;

	std::cout << c << std::endl;
	tryDecrement(c);
	tryIncrement(c);

	std::cout << "======================" << std::endl;
	std::cout << " Test 4: (ERROR)" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "Invalid constructors: grades 0 and 151" << std::endl;

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
