/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:31:50 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/11 19:04:03 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << MAGENTA << "Dog: Default constructor called" << RESET << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog& object): Animal(object)
{
	std::cout << BLUE << "Dog: Copy constructor called" << RESET << std::endl;
	_brain = new Brain(*object._brain);
}

Dog& Dog::operator=(const Dog& object)
{
	std::cout << WHITE << "Dog: Copy assignment operator called" << RESET << std::endl;
	if (this != &object)
	{
		Animal::operator=(object);
		delete _brain;
		_brain = new Brain(*object._brain);
	}

	return (*this);
}

Dog::~Dog()
{
	std::cout << RED << "Dog: Destructor called" << RESET << std::endl;
	delete _brain;
}

void Dog::makeSound() const
{
	std::cout << "Guau Guau!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return (_brain);
}
