/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:05:32 by tduprez           #+#    #+#             */
/*   Updated: 2023/07/25 14:26:20 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

int	main(int ac, char **av)
{
	int				index = 0;
	PhoneBook		repertory;
	std::string		userInput;
	(void)av;

	if (ac > 1)
		return (1);
	std::cout << "Welcome into PhoneBook !" << std::endl;
	std::cout << "For add user, type 'ADD'" << std::endl;
	std::cout << "For search user, type 'SEARCH'" << std::endl;
	std::cout << "For exit program, type 'EXIT'" << std::endl;
	while (true)
	{
		std::getline(std::cin, userInput);
		if (std::cin.eof())
		{
			std::cout << "Error ! An EOF was detected, please restart the program !" << std::endl;
			std::exit(1);
		}
		if (userInput == "ADD")
			addContact(repertory, index++);
		else if (userInput == "SEARCH")
			searchContact(repertory);
		else if (userInput == "EXIT")
			break ;
	}
	return (0);
}
