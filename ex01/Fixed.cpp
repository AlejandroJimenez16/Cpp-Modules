/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:38:04 by alejandj          #+#    #+#             */
/*   Updated: 2026/08/11 11:51:36 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed()
{
	std::cout << BOLD << MAGENTA << "Default constructor called" << RESET << std::endl;
	_fixedPointValue = 0;
}

// Int constructor
Fixed::Fixed(const int num)
{
	std::cout << BOLD << GREEN << "Int constructor called" << RESET << std::endl;
    
	// num << _fractionalBits == num * (2 ^ _fractionalBits) == num * 256
	_fixedPointValue = num << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float num)
{
	std::cout << BOLD << GREEN << "Float constructor called" << RESET << std::endl;
	_fixedPointValue = roundf(num * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed& object)
{
	std::cout << BOLD << BLUE << "Copy constructor called" << RESET << std::endl;
	*this = object;
}

// Assigment operator
Fixed& Fixed::operator=(const Fixed& object)
{
	std::cout << BOLD << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	if (this != &object)
		_fixedPointValue = object._fixedPointValue;

	return (*this);
}

// Destructor
Fixed::~Fixed()
{
	std::cout << BOLD << RED << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << BOLD << GREEN << "getRawBits member function called" << RESET << std::endl;
	return (_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{	
	return ((float)_fixedPointValue / (float)(1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (_fixedPointValue >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed& object)
{
	out << object.toFloat();
	return (out);
}
