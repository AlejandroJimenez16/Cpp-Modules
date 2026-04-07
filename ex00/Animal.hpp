/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:18:20 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/06 17:14:31 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define BOLD	"\033[1m"

#define RED     "\033[31m"
#define WHITE	"\033[37m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

class Animal
{
	protected:
		std::string type;
		
	public:
		Animal();
		Animal(const Animal& object);
		Animal& operator=(const Animal& object);
		virtual ~Animal();

		std::string getType() const;
		virtual void makeSound() const;
};

#endif