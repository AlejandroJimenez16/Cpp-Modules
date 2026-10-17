/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:07:45 by alejandj          #+#    #+#             */
/*   Updated: 2026/10/19 22:55:45 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& object);
		Bureaucrat& operator=(const Bureaucrat& object);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		
		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& object);

#endif