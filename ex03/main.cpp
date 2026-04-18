/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:50:28 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/18 21:20:41 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "\n============== Learn ==============\n" << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	
	// Test: Memory full
	Cure* cureptr = new Cure();
	src->learnMateria(cureptr);
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(cureptr);
	

	std::cout << "\n============== Equip ==============\n" << std::endl;
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	// Test: No exist materia
	tmp = src->createMateria("fire");
	me->equip(tmp);
	
	// Test: Segfault try delete same object
	AMateria* mat = src->createMateria("ice");
	me->equip(mat);

	std::cout << "\n============== Use ==============\n" << std::endl;
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	// Test: Use wrong index/no exist
	me->use(3, *bob);
	me->use(10, *bob);
	

	std::cout << "\n============== Unequip ==============\n" << std::endl;
	
	me->unequip(1);

	// Test: Use wrong index/no exist
	me->unequip(3);
	me->unequip(10);

	std::cout << "\n============== Copy ==============\n" << std::endl;
	
	Character* original = new Character("Original");
    Character* destino = new Character("Destino");
    
    AMateria* hielo = new Ice();
    destino->equip(hielo);
    destino->unequip(0); 
    
    *destino = *original; 

    delete original;
    delete destino;

	delete bob;
	delete me;
	delete src;

	return 0;
}
