/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:17:34 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/14 13:46:40 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_memory[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& object)
{
	for (int i = 0; i < 4; i++)
	{
		if (object._memory[i])
			_memory[i] = object._memory[i]->clone();
		else
			_memory[i] = nullptr;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& object)
{
	if (this != &object)
	{
		for (int i = 0; i < 4; i++)
			delete _memory[i];

		for (int i = 0; i < 4; i++)
		{
			if (object._memory[i])
				_memory[i] = object._memory[i]->clone();
			else
				_memory[i] = nullptr;
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
		if (!_memory[i])
		{
			_memory[i] = learn->clone();
			return ;
		}
	}

	std::cout << "Memory is full!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] && _memory[i]->getType() == type)
			return (_memory[i]->clone());
	}

	return (0);
}
