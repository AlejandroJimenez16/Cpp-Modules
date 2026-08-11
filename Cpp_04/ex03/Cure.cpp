/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 12:20:10 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/14 19:48:11 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::Cure(const Cure& object): AMateria(object) {}

Cure& Cure::operator=(const Cure& object)
{
    if (this != &object)
        AMateria::operator=(object);

    return (*this);
}

Cure::~Cure() {}

AMateria* Cure::clone() const
{
    AMateria* cure = new Cure();
    return (cure);
}

void Cure::use(ICharacter& target)
{
    std::cout << GREEN << "* heals " << RESET
              << target.getName() << "'s" << GREEN << " wounds *" << RESET << std::endl;
}
