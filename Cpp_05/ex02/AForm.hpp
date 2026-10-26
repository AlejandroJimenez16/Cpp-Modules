/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:44:21 by alejandj          #+#    #+#             */
/*   Updated: 2026/10/25 16:51:43 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExec;

	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExec);
		AForm(const AForm& object);
		AForm& operator=(const AForm& object);
		virtual ~AForm();

		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		void beSigned(const Bureaucrat& b);
		virtual void execute(const Bureaucrat& executor) const = 0;

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

		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& object);

#endif