/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:17:11 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/11 18:54:00 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << MAGENTA << "Animal: Default constructor called" << RESET << std::endl;
	_type = "None";
}

Animal::Animal(const Animal& object)
{
	std::cout << BLUE << "Animal: Copy constructor called" << RESET << std::endl;
	_type = object._type;
}

Animal& Animal::operator=(const Animal& object)
{
	std::cout << WHITE << "Animal: Copy assignment operator called" << RESET << std::endl;
	if (this != &object)
		_type = object._type;

	return (*this);
}

Animal::~Animal()
{
	std::cout << RED << "Animal: Destructor called" << RESET << std::endl;
}

std::string Animal::getType() const
{
	return (_type);
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
