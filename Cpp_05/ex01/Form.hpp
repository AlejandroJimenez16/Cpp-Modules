/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:44:21 by alejandj          #+#    #+#             */
/*   Updated: 2026/10/19 23:06:04 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExec;

	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& object);
		Form& operator=(const Form& object);
		~Form();

		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		void beSigned(const Bureaucrat& b);

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

std::ostream& operator<<(std::ostream& out, const Form& object);

#endif