/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:10:46 by alejandj          #+#    #+#             */
/*   Updated: 2026/03/10 15:35:16 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& object);
		Fixed& operator=(const Fixed& object);
		~Fixed();
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		float toFloat(void) const;
		int toInt( void ) const;

		bool operator>(const Fixed& object) const;
		bool operator<(const Fixed& object) const;
		bool operator>=(const Fixed& object) const;
		bool operator<=(const Fixed& object) const;
		bool operator==(const Fixed& object) const;
		bool operator!=(const Fixed& object) const;

		Fixed operator+(const Fixed& object);
		Fixed operator-(const Fixed& object);
		Fixed operator*(const Fixed& object);
		Fixed operator/(const Fixed& object);

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed& min(Fixed& fp1, Fixed& fp2);
		static const Fixed& min(const Fixed& fp1, const Fixed& fp2);
		static Fixed& max(Fixed& fp1, Fixed& fp2);
		static const Fixed& max(const Fixed& fp1, const Fixed& fp2);
};

std::ostream &operator<<(std::ostream &out, const Fixed& object);

#endif