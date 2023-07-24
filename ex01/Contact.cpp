/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:06:26 by tduprez           #+#    #+#             */
/*   Updated: 2023/07/24 16:58:32 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/PhoneBook.hpp"

static std::string	getUserInput(const char *prompt);

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::addContact(const char *prompt, int whichData)
{
	std::string	userInput;

	userInput = getUserInput(prompt);
	switch (whichData)
	{
		case FIRSTNAME:
			this->_firstName = userInput;
			break ;
		case LASTNAME:
			this->_lastName = userInput;
			break ;
		case NICKNAME:
			this->_nickname = userInput;
			break ;
		case PHONENUMBER:
			this->_phoneNumber = userInput;
			break ;
		case SECRET:
			this->_secret = userInput;
			break ;
	}
	return ;
}

std::string	Contact::getData(int whichData) const
{
	std::string	data;

	switch (whichData) {
		case FIRSTNAME:
			return (this->_firstName);
		case LASTNAME:
			return (this->_lastName);
		case NICKNAME:
			return (this->_nickname);
		case PHONENUMBER:
			return (this->_phoneNumber);
		case SECRET:
			return (this->_secret);
	}
	return (NULL);
}

void	Contact::printData(int whichData) const
{
	int			nbSpaces;
	int			max = 10;
	bool		needDot = false;
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

static std::string	getUserInput(const char *prompt)
{
	std::string	userInput;

	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, userInput);
		if (std::cin.eof())
		{
			std::cout << "Error ! An EOF was detected, please restart the program !" << std::endl;
			std::exit(1);
		} else if (userInput.empty() || isAllIsspace(userInput))
			continue ;
		break ;
	}
	return (userInput);
}
