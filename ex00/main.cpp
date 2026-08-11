/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:56:06 by alejandj          #+#    #+#             */
/*   Updated: 2026/08/11 18:27:34 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "\n============== Normal ==============\n" << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	std::cout << "\n============== Wrong ==============\n" << std::endl;
	
	const WrongAnimal* k = new WrongCat();

	std::cout << std::endl;
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();

	std::cout << "\n============== Destructors ==============\n" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete k;
	
	return (0);
}
