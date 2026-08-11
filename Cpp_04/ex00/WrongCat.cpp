/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:57:02 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/11 18:51:32 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << MAGENTA << "WrongCat: Default constructor called" << RESET << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& object): WrongAnimal(object)
{
	std::cout << BLUE << "WrongCat: Copy constructor called" << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& object)
{
	std::cout << WHITE << "WrongCat: Copy assignment operator called" << RESET << std::endl;
	if (this != &object)
		WrongAnimal::operator=(object);

	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat: Destructor called" << RESET << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Miau Miau! (WrongCat)" << std::endl;
}
