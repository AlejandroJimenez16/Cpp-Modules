/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 18:27:04 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/14 13:58:49 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
	_type = "None";
}

AMateria::AMateria(std::string const & type)
{
	_type = type;
}

AMateria::AMateria(const AMateria& object)
{
	_type = object._type;
}

AMateria& AMateria::operator=(const AMateria& object)
{
	if (this != &object)
		_type = object._type;

	return (*this);
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

