/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:50:06 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/11 18:58:26 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << MAGENTA << "Cat: Default constructor called" << RESET << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat& object): Animal(object)
{
	std::cout << BLUE << "Cat: Copy constructor called" << RESET << std::endl;
	_brain = new Brain(*object._brain);
}

Cat& Cat::operator=(const Cat& object)
{
	std::cout << WHITE << "Cat: Copy assignment operator called" << RESET << std::endl;
	if (this != &object)
	{
		Animal::operator=(object);
		delete _brain;
		_brain = new Brain(*object._brain);
	}

	return (*this);
}

Cat::~Cat()
{
	std::cout << RED << "Cat: Destructor called" << RESET << std::endl;
	delete _brain;
}

void Cat::makeSound() const
{
	std::cout << "Miau Miau!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return (_brain);
}
