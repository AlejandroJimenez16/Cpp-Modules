/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:17:34 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/18 21:39:04 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_memory[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& object)
{
	for (int i = 0; i < 4; i++)
	{
		if (object._memory[i])
			_memory[i] = object._memory[i]->clone();
		else
			_memory[i] = 0;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& object)
{
	if (this != &object)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _memory[i];
			if (object._memory[i])
				_memory[i] = object._memory[i]->clone();
			else
				_memory[i] = 0;
		}
	}

	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete _memory[i];
}

void MateriaSource::learnMateria(AMateria* learn)
{
	if (!learn)
		return ;

	
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] == learn)
			return ;
	}
	

	for (int i = 0; i < 4; i++)
	{
		if (!_memory[i])
		{
			std::cout << MAGENTA << "[" << learn->getType() << "] Materia has been learned!" << RESET << std::endl;
			_memory[i] = learn;
			return ;
		}
	}

	delete learn;
	std::cout << RED << "[!] Memory is full!" << RESET << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] && _memory[i]->getType() == type)
			return (_memory[i]->clone());
	}

	std::cout << YELLOW << "[" << type << "] Materia type not found!" << RESET << std::endl;
	return (0);
}
