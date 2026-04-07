/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:48:14 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/06 17:53:40 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << MAGENTA << "WrongAnimal: Default constructor called" << RESET << std::endl;
	type = "None";
}

WrongAnimal::WrongAnimal(const WrongAnimal& object)
{
	std::cout << BLUE << "WrongAnimal: Copy constructor called" << RESET << std::endl;
	type = object.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& object)
{
	std::cout << WHITE << "WrongAnimal: Copy assignment operator called" << RESET << std::endl;
	if (this != &object)
		type = object.type;

	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal: Destructor called" << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}
