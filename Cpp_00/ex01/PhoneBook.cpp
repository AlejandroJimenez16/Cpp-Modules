/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:36:20 by alejandj          #+#    #+#             */
/*   Updated: 2026/08/09 17:44:17 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>

PhoneBook::PhoneBook()
{
    this->index = 0;
	this->count = 0;
}

static int checkLetters(std::string str)
{
	int i = 0;

	while (str[i])
	{
		if (!isalpha(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int checkNumbers(std::string str)
{
	int i = 0;

	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
* 0 -> Validate letters
* 1 -> Validate numbers
* 2 -> Validate index
* 3 -> No Validation
*/
static std::string ftReadLine(std::string prompt, int type)
{
	std::string	var;

    while (true)
    {
		std::cout << prompt;
		std::getline(std::cin, var);

		if (std::cin.eof())
			return "";

		var.erase(0, var.find_first_not_of(" \t\n\r\v\f"));
		var.erase(var.find_last_not_of(" \t\n\r\v\f") + 1);

		if (var.empty())
		{
			std::cout << BOLD << RED << "❌ Empty field"<< RESET << std::endl;
			continue ;
		}

		if (type == 0 && !checkLetters(var))
		{
			std::cout << BOLD << RED << "❌ Only letters allowed" << RESET << std::endl;
			continue ;
		}

		if ((type == 1 || type == 2) && !checkNumbers(var))
		{
			if (type == 1)
				std::cout << BOLD << RED << "❌ Only numbers allowed" << RESET << std::endl;
			else
				std::cout << BOLD << RED << "❌ Invalid index" << RESET << std::endl;
			continue ;
		}

		if (!var.empty())
			break ;
    }
	return (var);
}

int PhoneBook::addContact()
{
	std::string firstName;
	std::string lastName;
    std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	firstName = ftReadLine("First name: ", 0);
	if (firstName.empty())
		return (-1);
	lastName = ftReadLine("Last name: ", 0);
	if (lastName.empty())
		return (-1);
	nickname = ftReadLine("Nickname: ", 3);
	if (nickname.empty())
		return (-1);
	phoneNumber = ftReadLine("Phone number: ", 1);
	if (phoneNumber.empty())
		return (-1);
	darkestSecret = ftReadLine("Darkest secret: ", 3);
	if (darkestSecret.empty())
		return (-1);
	
	Contact c(firstName, lastName, nickname, phoneNumber, darkestSecret);
	contactList[index] = c;
	index = (index + 1) % 8;
	if (count < 8)
		count++;
	
	std::cout << BOLD << GREEN << "✅ Contact added successfully!" << RESET << std::endl;
	std::cout << std::endl;
	
	return (0);
}

static void	printTable(int count, Contact contactList[8])
{
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	
	int i = 0;	
	while (i < count)
	{
		std::cout << "|" << std::setw(10) << i << "|";

		if (contactList[i].getFirstName().length() > 10)
			std::cout << contactList[i].getFirstName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << contactList[i].getFirstName() << "|";
		
		if (contactList[i].getLastName().length() > 10)
			std::cout << contactList[i].getLastName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << contactList[i].getLastName() << "|";

		if (contactList[i].getNickname().length() > 10)
			std::cout << contactList[i].getNickname().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << contactList[i].getNickname() << "|";
			
		std::cout << std::endl;
		
		if (i < count - 1) 
			std::cout << "+----------+----------+----------+----------+" << std::endl;
		i++; 
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

int PhoneBook::searchContact()
{	
	std::string input;
	int n;
	
	printTable(count, contactList);
	
	input = ftReadLine(BOLD YELLOW "Insert index: " RESET, 2);
	
	if (std::cin.eof())
		return (-1);

	std::istringstream iss(input);
	iss >> n;
	
	if (n >= count)
		std::cout << "Contact not found" << std::endl;
	else
	{	
		std::cout << "First name: " << contactList[n].getFirstName() << std::endl;
		std::cout << "Last name: " << contactList[n].getLastName() << std::endl;
		std::cout << "Nickname: " << contactList[n].getNickname() << std::endl;
		std::cout << "Phone number: " << contactList[n].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << contactList[n].getDarkestSecret() << std::endl;
	}
	std::cout << std::endl;
	
	return (0);
}
