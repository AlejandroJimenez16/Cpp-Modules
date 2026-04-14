/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:56:53 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/14 13:27:31 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	_name = "";
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(std::string name)
{
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const Character& object)
{
	_name = object._name;
	for (int i = 0; i < 4; i++)
	{
		if (object._inventory[i])
			_inventory[i] = object._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
}

Character& Character::operator=(const Character& object)
{
	if (this != &object)
	{
		_name = object._name;
		
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
		}

		for (int i = 0; i < 4; i++)
		{
			if (object._inventory[i])
				_inventory[i] = object._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
	
	}

	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}
std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
	
	std::cout << "Inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;
	
	_inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		return ;

	if (_inventory[idx])
		_inventory[idx]->use(target);
}
