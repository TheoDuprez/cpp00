/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:05:32 by tduprez           #+#    #+#             */
/*   Updated: 2023/07/18 16:05:09 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookClass.hpp"
#include <string>
#include <stdio.h>

bool		isAllIsspace(std::string s);
std::string	addContactLoop(PhoneBook *repertory, const char *prompt);

int	main(void)
{
	int				i = 0;
	PhoneBook		repertory;
	Contact			temp;
	std::string		userInput;

	while (true)
	{
		std::getline(std::cin, userInput);
		if (std::cin.eof())
		{
			std::cout << "Error ! An EOF was detected, please restart the program !" << std::endl;
			std::_Exit(1);
		}
		if (userInput == "ADD")
		{
			if (i >= 8)
			{
				for (int i = 0; i < 7; i++)
					repertory.contacts[i] = repertory.contacts[i + 1];
				repertory.contacts[7].addContact("First name : ", FIRSTNAME);
				repertory.contacts[7].addContact("Last name : ", LASTNAME);
				repertory.contacts[7].addContact("Phone number : ", PHONENUMBER);
				repertory.contacts[7].addContact("Darkest secret : ", SECRET);
			} else {
				repertory.contacts[i].addContact("First name : ", FIRSTNAME);
				repertory.contacts[i].addContact("Last name : ", LASTNAME);
				repertory.contacts[i].addContact("Phone number : ", PHONENUMBER);
				repertory.contacts[i].addContact("Darkest secret : ", SECRET);
			}
			i++;
		} else if (userInput == "SEARCH") {
			for (int i = 0; i < 8; i++)
			{
				if (repertory.contacts[i].getData(FIRSTNAME).empty() == false)
				{
					repertory.contacts[i].printData(FIRSTNAME);
					repertory.contacts[i].printData(LASTNAME);
					repertory.contacts[i].printData(PHONENUMBER);
					repertory.contacts[i].printData(SECRET);
					std::cout << "|" << std::endl;
				}
			}
			std::cout << "Select an index to print the data : ";
			std::getline(std::cin, userInput);
			if (std::stoi(userInput) < 7 && repertory.contacts[std::stoi(userInput)].getData(FIRSTNAME).empty() == false)
			{
				std::cout << "First name     : " << repertory.contacts[std::stoi(userInput)].getData(FIRSTNAME) << std::endl;
				std::cout << "Last name      : " << repertory.contacts[std::stoi(userInput)].getData(LASTNAME) << std::endl;
				std::cout << "Phone number   : " << repertory.contacts[std::stoi(userInput)].getData(PHONENUMBER) << std::endl;
				std::cout << "Darkest secret : " << repertory.contacts[std::stoi(userInput)].getData(SECRET) << std::endl;
			}
			else
				std::cout << "Error ! This index or this contact does not exist !" << std::endl;
		} else if (userInput == "EXIT")
			break ;
	}
}

bool	isAllIsspace(std::string s)
{
	int	count = 0;

	for (int i = 0; s[i]; i++)
		if ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
			count++;
	if (count != 0 && count == s.length())
		return (true);
	return (false);
}
