/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:50:06 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/09 12:37:37 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << MAGENTA << "Cat: Default constructor called" << RESET << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& object): Animal(object)
{
	std::cout << BLUE << "Cat: Copy constructor called" << RESET << std::endl;
	brain = new Brain(*object.brain);
}

Cat& Cat::operator=(const Cat& object)
{
	std::cout << WHITE << "Cat: Copy assignment operator called" << RESET << std::endl;
	if (this != &object)
	{
		Animal::operator=(object);
		delete brain;
		brain = new Brain(*object.brain);
	}

	return (*this);
}

Cat::~Cat()
{
	std::cout << RED << "Cat: Destructor called" << RESET << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Miau Miau!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return (brain);
}
