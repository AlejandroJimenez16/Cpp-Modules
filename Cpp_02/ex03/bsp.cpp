/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 19:53:23 by alejandj          #+#    #+#             */
/*   Updated: 2026/03/17 17:18:06 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed calculateArea(Point const p1, Point const p2, Point const p3)
{
	Fixed area;

	area = (p1.getX() * (p2.getY() - p3.getY()) + 
			p2.getX() * (p3.getY() - p1.getY()) +
			p3.getX() * (p1.getY() - p2.getY()))
		/ Fixed(2);
		
	if (area < Fixed(0))
		area = area * Fixed(-1);
		
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaAbc = calculateArea(a, b, c);
	
	Fixed areaPab = calculateArea(point, a, b);
	Fixed areaPbc = calculateArea(point, b, c);
	Fixed areaPac = calculateArea(point, a, c);

	if (areaPab == Fixed(0) || areaPbc == Fixed(0) || areaPac == Fixed(0))
	{
		std::cout << BOLD << RED << "Point is a vertex or an edge" << RESET << std::endl;
		return (false);		
	}

	if (areaPab + areaPbc + areaPac == areaAbc)
	{
		std::cout << BOLD << GREEN << "Point is inside the triangle" << RESET << std::endl;
		return (true);
	}
	else
	{
		std::cout << BOLD << RED << "Point is outside the triangle" << RESET << std::endl;
		return (false);
	}
}
