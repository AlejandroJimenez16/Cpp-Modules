/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 19:29:13 by alejandj          #+#    #+#             */
/*   Updated: 2026/11/09 13:06:14 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm* createShrubbery(const std::string& target);
		AForm* createRobotomy(const std::string& target);
		AForm* createPresidential(const std::string& target);

	public:
		Intern();
		Intern(const Intern& object);
		Intern& operator=(const Intern& object);
		~Intern();

		AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif