/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:41:50 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/11 18:50:50 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

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

class WrongAnimal
{
    protected:
		std::string _type;
		
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& object);
		WrongAnimal& operator=(const WrongAnimal& object);
		virtual ~WrongAnimal();

		std::string getType() const;
		void makeSound() const;
};

#endif