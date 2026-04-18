/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 12:14:52 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/18 21:29:12 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure& object);
		Cure& operator=(const Cure& object);
		~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif