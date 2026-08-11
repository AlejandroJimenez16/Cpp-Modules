/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:18:41 by alejandj          #+#    #+#             */
/*   Updated: 2026/08/11 11:51:56 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed()
{
	_fixedPointValue = 0;
}

// Int constructor
Fixed::Fixed(const int num)
{   
	// num << _fractionalBits == num * (2 ^ _fractionalBits) == num * 256
	_fixedPointValue = num << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float num)
{
	_fixedPointValue = roundf(num * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed& object)
{
	*this = object;
}

// Assigment operator
Fixed& Fixed::operator=(const Fixed& object)
{
	if (this != &object)
		_fixedPointValue = object._fixedPointValue;

	return (*this);
}

// Destructor
Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
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

bool Fixed::operator>(const Fixed& object) const
{
	return (_fixedPointValue > object._fixedPointValue);
}

bool Fixed::operator<(const Fixed& object) const
{
	return (_fixedPointValue < object._fixedPointValue);
}

bool Fixed::operator>=(const Fixed& object) const
{
	return (_fixedPointValue >= object._fixedPointValue);
}

bool Fixed::operator<=(const Fixed& object) const
{
	return (_fixedPointValue <= object._fixedPointValue);
}

bool Fixed::operator==(const Fixed& object) const
{
	return (_fixedPointValue == object._fixedPointValue);
}

bool Fixed::operator!=(const Fixed& object) const
{
	return (_fixedPointValue != object._fixedPointValue);
}

Fixed Fixed::operator+(const Fixed& object)
{
	return (Fixed(this->toFloat() + object.toFloat()));
}

Fixed Fixed::operator-(const Fixed& object)
{
	return (Fixed(this->toFloat() - object.toFloat()));
}

Fixed Fixed::operator*(const Fixed& object)
{
	return (Fixed(this->toFloat() * object.toFloat()));
}

Fixed Fixed::operator/(const Fixed& object)
{
	return (Fixed(this->toFloat() / object.toFloat()));
}

Fixed& Fixed::operator++()
{
	// Pre-increment: add 1 to the internal fixed-point value
	// This corresponds to increasing the real value by ε = 1 / 2^_fractionalBits
	_fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	
	_fixedPointValue++;
	return (temp);
}

Fixed& Fixed::operator--()
{
	_fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	
	_fixedPointValue--;
	return (temp);
}

Fixed& Fixed::min(Fixed& fp1, Fixed& fp2)
{
	if (fp1._fixedPointValue < fp2._fixedPointValue)
		return (fp1);
	else
		return (fp2);
}

const Fixed& Fixed::min(const Fixed& fp1, const Fixed& fp2)
{
	if (fp1._fixedPointValue < fp2._fixedPointValue)
		return (fp1);
	else
		return (fp2);
}

Fixed& Fixed::max(Fixed& fp1, Fixed& fp2)
{
	if (fp1._fixedPointValue > fp2._fixedPointValue)
		return (fp1);
	else
		return (fp2);
}

const Fixed& Fixed::max(const Fixed& fp1, const Fixed& fp2)
{
	if (fp1._fixedPointValue > fp2._fixedPointValue)
		return (fp1);
	else
		return (fp2);
}

std::ostream &operator<<(std::ostream &out, const Fixed& object)
{
	out << object.toFloat();
	return (out);
}
