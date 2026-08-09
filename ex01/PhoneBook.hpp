/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:59:36 by alejandj          #+#    #+#             */
/*   Updated: 2026/08/09 16:57:47 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "colors.hpp"

class PhoneBook
{
	private:
		int		index;
		int		count;
		Contact contactList[8];

	public:
		PhoneBook();
		int addContact(void);
		int searchContact(void);
};

#endif