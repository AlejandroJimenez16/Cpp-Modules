/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:40:44 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/09 13:37:43 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << MAGENTA << "Brain: Default constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "default";
}

Brain::Brain(const Brain& object)
{
	std::cout << BLUE << "Brain: Copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = object.ideas[i];
}

Brain& Brain::operator=(const Brain& object)
{
	std::cout << WHITE << "Brain: Copy assignment operator called" << RESET << std::endl;
	if (this != &object)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = object.ideas[i];
	}

	return (*this);
}

Brain::~Brain()
{
	std::cout << RED << "Brain: Destructor called" << RESET << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (ideas[index]);
	else
		return ("");
}

void Brain::setIdea(int index, std::string idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
	else
		std::cout << "Invalid index" << std::endl;
}
