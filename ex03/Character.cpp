/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:56:53 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/20 23:29:15 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	_name = "";
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;

	_floorCount = 0;
	for (int i = 0; i < 50; i++)
		_floor[i] = 0;
}

Character::Character(std::string name)
{
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;

	_floorCount = 0;
	for (int i = 0; i < 50; i++)
		_floor[i] = 0;
}

Character::Character(const Character& object)
{
	_name = object._name;
	for (int i = 0; i < 4; i++)
	{
		if (object._inventory[i])
			_inventory[i] = object._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}

	_floorCount = 0;
	for (int i = 0; i < 50; i++)
		_floor[i] = 0;
}

Character& Character::operator=(const Character& object)
{
	if (this != &object)
	{
		_name = object._name;

		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			if (object._inventory[i])
				_inventory[i] = object._inventory[i]->clone();
			else
				_inventory[i] = 0;
		}

		_floorCount = 0;
		for (int i = 0; i < 50; i++)
		{
			delete _floor[i];
			_floor[i] = 0;
		}
	}

	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];

	for (int i = 0; i < 50; i++)
		delete _floor[i];
}
std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;

	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == m)
		{
			std::cout << YELLOW << "[" << m->getType() << "] Materia is already equipped!" << RESET << std::endl;
			return ;
		}
	}

	for (int i = 0; i < _floorCount; i++)
	{
		if (_floor[i] == m)
			return ;
	}

	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			std::cout << MAGENTA << "[" << m->getType() << "] Materia has been equipped!" << RESET << std::endl;
			_inventory[i] = m;
			return ;
		}
	}
	
	std::cout << RED << "[!] Inventory is full!" << RESET << std::endl;
	if (_floorCount < 50)
	{
		_floor[_floorCount] = m;
		_floorCount++;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << RED << "[!] Invalid index" << RESET << std::endl;
		return ;
	}

	if (!_inventory[idx])
	{
		std::cout << YELLOW << "[!] Empty slot" << RESET << std::endl;
		return ;
	}

	if (_floorCount < 50)
	{
		std::cout << MAGENTA << "[" << _inventory[idx]->getType() << "] Materia has been unequipped!" << RESET << std::endl;
		_floor[_floorCount] = _inventory[idx];
		_floorCount++;
		_inventory[idx] = 0;
	}
	else
	{
		std::cout << RED << "[!] Floor is full!" << RESET << std::endl;
		return ;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << RED << "[!] Invalid index" << RESET << std::endl;
		return ;
	}

	if (_inventory[idx])
		_inventory[idx]->use(target);
	else
    	std::cout << YELLOW << "[!] No materia in this slot!" << RESET << std::endl;
}
