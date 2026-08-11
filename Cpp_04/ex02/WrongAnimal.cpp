/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:48:14 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/11 18:51:23 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << MAGENTA << "WrongAnimal: Default constructor called" << RESET << std::endl;
	_type = "None";
}

WrongAnimal::WrongAnimal(const WrongAnimal& object)
{
	std::cout << BLUE << "WrongAnimal: Copy constructor called" << RESET << std::endl;
	_type = object._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& object)
{
	std::cout << WHITE << "WrongAnimal: Copy assignment operator called" << RESET << std::endl;
	if (this != &object)
		_type = object._type;

	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal: Destructor called" << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}
