/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:35:14 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/08 19:02:55 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define BOLD	"\033[1m"

#define RED     "\033[31m"
#define WHITE	"\033[37m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain& object);
		Brain& operator=(const Brain& object);
		~Brain();

		std::string getIdea(int index) const;
		void setIdea(int index, std::string idea);
};

#endif