/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:06:26 by tduprez           #+#    #+#             */
/*   Updated: 2023/07/18 15:34:16 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookClass.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::getData(int whichData) const
{
	std::string	data;

	switch (whichData) {
		case 1:
			return (this->firstName);
		case 2:
			return (this->lastName);
		case 3:
			return (this->phoneNumber);
		case 4:
			return (this->secret);
	}
	return (NULL);
}

void	Contact::printData(int whichData) const
{
	int		nbSpaces;
	int		max = 10;
	bool	needDot = false;
	std::string	str = this->getData(whichData);

	nbSpaces = 10 - str.length();
	std::cout << "|";
	if (nbSpaces > 0)
		for (int i = 0; i < nbSpaces; i++)
			std::cout << " ";
	if (str.length() > 10)
	{
		needDot = true;
		max--;
	}
	for (int i = 0; i < max && str[i]; i++)
		std::cout << str[i];
	if (needDot == true)
		std::cout << ".";
}

void	Contact::addContact(const char *prompt, int whichData)
{
	std::string	userInput;

	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, userInput);
		if (std::cin.eof())
		{
			std::cout << "Error ! An EOF was detected, please restart the program !" << std::endl;
			std::_Exit(1);
		} else if (userInput.empty() || isAllIsspace(userInput))
			continue ;
		break ;
	}
	switch (whichData)
	{
		case 1:
			this->firstName = userInput;
		case 2:
			this->lastName = userInput;
		case 3:
			this->phoneNumber = userInput;
		case 4:
			this->secret = userInput;
	}
	return ;
}

