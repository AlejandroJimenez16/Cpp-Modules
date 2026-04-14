/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 19:16:11 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/13 12:11:09 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

#define RESET "\033[0m"
#define CYAN  "\033[36m"

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice& object);
		Ice& operator=(const Ice& object);
		~Ice();
		
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif