/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 19:23:25 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/14 14:02:59 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice& object): AMateria(object) {}

Ice& Ice::operator=(const Ice& object)
{
	if (this != &object)
		AMateria::operator=(object);

	return (*this);
}

Ice::~Ice() {}

AMateria* Ice::clone() const
{
	AMateria* object = new Ice();
	return (object);
}

void Ice::use(ICharacter& target)
{
	std::cout << "Ice: " << CYAN << "* shoots an ice bolt at " << RESET<< target.getName() << " *" << std::endl;
}
