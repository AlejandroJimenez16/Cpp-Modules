/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:56:06 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/21 13:20:21 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	//Animal a;
	//Animal* b = new Animal();
	
	int N = 10;
	Animal* animals[N];
	
	std::cout << "============== Creation ==============\n" << std::endl;
	
	for (int i = 0; i < N / 2; i++)
	{
		std::cout << "Dog: " << i + 1 << std::endl;
		animals[i] = new Dog();
	}

	for (int i = N / 2; i < N; i++)
	{
		std::cout << "Cat: " << i - N/2 + 1 << std::endl;
		animals[i] = new Cat();
	}

	std::cout << "\n============== Test ==============\n" << std::endl;

	Dog* originalDog = new Dog();
	originalDog->getBrain()->setIdea(0, "42");

	Dog* copyDog = new Dog(*originalDog);
	copyDog->getBrain()->setIdea(0, "21");
	
	std::cout << std::endl;
	std::cout << "Original idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;
	
	
	std::cout << "\n============== Destructors ==============\n" << std::endl;

	for (int i = 0; i < N; i++)
	{
		std::cout << "Object: " << i + 1 << std::endl;
		delete animals[i];
	}

	std::cout << "\nOriginal Dog:" << std::endl;
	delete originalDog;
	std::cout << "Copy Dog:" << std::endl;
	delete copyDog;
	
	return 0;
}
