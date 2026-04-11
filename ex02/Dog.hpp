/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:09:17 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/11 19:03:31 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain* _brain;
	
	public:
		Dog();
		Dog(const Dog& object);
		Dog& operator=(const Dog& object);
		~Dog();

		void makeSound() const;
		Brain* getBrain() const;
};

#endif