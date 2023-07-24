/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:46:10 by tduprez           #+#    #+#             */
/*   Updated: 2023/07/24 16:46:47 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/PhoneBook.hpp"

void	addContact(PhoneBook& repertory, int index)
{
	if (index >= 8)
	{
		for (int i = 0; i < 7; i++)
			repertory.contacts[i] = repertory.contacts[i + 1];
		repertory.contacts[7].addContact("First name     : ", FIRSTNAME);
		repertory.contacts[7].addContact("Last name      : ", LASTNAME);
		repertory.contacts[7].addContact("Nickname       : ", NICKNAME);
		repertory.contacts[7].addContact("Phone number   : ", PHONENUMBER);
		repertory.contacts[7].addContact("Darkest secret : ", SECRET);
	} else {
		repertory.contacts[index].addContact("First name     : ", FIRSTNAME);
		repertory.contacts[index].addContact("Last name      : ", LASTNAME);
		repertory.contacts[index].addContact("Nickname       : ", NICKNAME);
		repertory.contacts[index].addContact("Phone number   : ", PHONENUMBER);
		repertory.contacts[index].addContact("Darkest secret : ", SECRET);
	}
}

void	searchContact(PhoneBook& repertory)
{
	std::string		userInput;

	for (int i = 0; i < 8; i++)
	{
		if (repertory.contacts[i].getData(FIRSTNAME).empty() == false)
		{
			std::cout << "|         " << i;
			repertory.contacts[i].printData(FIRSTNAME);
			repertory.contacts[i].printData(LASTNAME);
			repertory.contacts[i].printData(NICKNAME);
			std::cout << "|" << std::endl;
		}
	}
	std::cout << "Select an index to print the data : ";
	std::getline(std::cin, userInput);
	if (atoi(userInput.c_str()) < 7 && !userInput.empty() && \
	repertory.contacts[atoi(userInput.c_str())].getData(FIRSTNAME).empty() == false)
	{
		std::cout << "First name     : " << repertory.contacts[atoi(userInput.c_str())].getData(FIRSTNAME) << std::endl;
		std::cout << "Last name      : " << repertory.contacts[atoi(userInput.c_str())].getData(LASTNAME) << std::endl;
		std::cout << "Nickname       : " << repertory.contacts[atoi(userInput.c_str())].getData(NICKNAME) << std::endl;
		std::cout << "Phone number   : " << repertory.contacts[atoi(userInput.c_str())].getData(PHONENUMBER) << std::endl;
		std::cout << "Darkest secret : " << repertory.contacts[atoi(userInput.c_str())].getData(SECRET) << std::endl;
	}
	else
		std::cout << "Error ! This index does not exist !" << std::endl;
}

bool	isAllIsspace(std::string s)
{
	int	count = 0;

	for (int i = 0; s[i]; i++)
		if ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
			count++;
	if (count != 0 && count == (int)s.length())
		return (true);
	return (false);
}
