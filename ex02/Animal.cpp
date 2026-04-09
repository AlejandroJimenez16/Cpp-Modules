/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:17:11 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/09 12:37:10 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << MAGENTA << "Animal: Default constructor called" << RESET << std::endl;
	type = "None";
}

Animal::Animal(const Animal& object)
{
	std::cout << BLUE << "Animal: Copy constructor called" << RESET << std::endl;
	type = object.type;
}

Animal& Animal::operator=(const Animal& object)
{
	std::cout << WHITE << "Animal: Copy assignment operator called" << RESET << std::endl;
	if (this != &object)
		type = object.type;

	return (*this);
}

Animal::~Animal()
{
	std::cout << RED << "Animal: Destructor called" << RESET << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
