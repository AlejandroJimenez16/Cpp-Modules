/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:47:47 by alejandj          #+#    #+#             */
/*   Updated: 2026/08/11 11:52:51 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point const a(1, 2);
	Point const b(4, 1);
	Point const c(7, 4);
	
	// Vertex
	Point const p1(1, 2);
	// Edge
	Point const p2(5, 2);
	// Outside
	Point const p3(4, 4);
	// Inside
	Point const p4(3, 2);

	std::cout << "==============================" << std::endl;
	std::cout << "Vertex:" << std::endl;
	bsp(a, b, c, p1);

	std::cout << "\nEdge:" << std::endl;
	bsp(a, b, c, p2);

	std::cout << "\nOutside:" << std::endl;
	bsp(a, b, c, p3);

	std::cout << "\nInside:" << std::endl;
	bsp(a, b, c, p4);
	std::cout << "==============================" << std::endl;

	return (0);
}
