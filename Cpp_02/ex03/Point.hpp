/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 19:57:44 by alejandj          #+#    #+#             */
/*   Updated: 2026/03/18 13:52:48 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define BOLD	"\033[1m"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
    
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& object);
		Point& operator=(const Point& object);
		~Point();

		Fixed getX() const;
		Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif