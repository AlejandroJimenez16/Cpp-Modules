/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:50:06 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/11 18:50:23 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << MAGENTA << "Cat: Default constructor called" << RESET << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& object): Animal(object)
{
	std::cout << BLUE << "Cat: Copy constructor called" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& object)
{
	std::cout << WHITE << "Cat: Copy assignment operator called" << RESET << std::endl;
	if (this != &object)
		Animal::operator=(object);

	return (*this);
}

Cat::~Cat()
{
	std::cout << RED << "Cat: Destructor called" << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miau Miau!" << std::endl;
}
