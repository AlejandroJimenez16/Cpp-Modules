/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 20:18:28 by alejandj          #+#    #+#             */
/*   Updated: 2026/03/16 12:46:34 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor
Point::Point(): _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

// Copy constructor
Point::Point(const Point& object): _x(object._x), _y(object._y) {}

// Assigment operator
Point& Point::operator=(const Point& object)
{
	(void)object;
	return (*this);
}

Point::~Point() {}

Fixed Point::getX() const
{
	return (_x);
}

Fixed Point::getY() const
{
	return (_y);
}
