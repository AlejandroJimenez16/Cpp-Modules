/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:31:50 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/06 16:44:21 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << MAGENTA << "Dog: Default constructor called" << RESET << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& object): Animal(object)
{
	std::cout << BLUE << "Dog: Copy constructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& object)
{
	std::cout << WHITE << "Dog: Copy assignment operator called" << RESET << std::endl;
	if (this != &object)
		Animal::operator=(object);

	return (*this);
}

Dog::~Dog()
{
	std::cout << RED << "Dog: Destructor called" << RESET << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Guau Guau!" << std::endl;
}
