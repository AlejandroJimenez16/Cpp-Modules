/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:03:18 by alejandj          #+#    #+#             */
/*   Updated: 2026/08/09 17:40:46 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}

Contact::Contact(
    const std::string firstName,
    const std::string lastName,
	const std::string nickname,
    const std::string phoneNumber,
    const std::string darkestSecret
)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName()
{
    return firstName;
}

std::string Contact::getLastName()
{
    return lastName;
}

std::string Contact::getNickname()
{
    return nickname;
}

std::string Contact::getPhoneNumber()
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret()
{
    return darkestSecret;
}
