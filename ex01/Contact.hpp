/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:44:13 by alejandj          #+#    #+#             */
/*   Updated: 2026/08/09 17:43:54 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		Contact();
		Contact(
			const std::string firstName,
			const std::string lastName,
			const std::string nickname,
			const std::string phoneNumber,
			const std::string darkestSecret
		);

		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
};

#endif