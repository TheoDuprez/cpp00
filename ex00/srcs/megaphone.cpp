/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:15:02 by tduprez           #+#    #+#             */
/*   Updated: 2023/07/25 14:20:42 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	megaphone(char **av);

int	main(int ac, char **av)
{
	if (ac > 1)
		megaphone(av + 1);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

void	megaphone(char **av)
{
	std::string	str;

	for (int i = 0; av[i]; i++)
	{
		str = av[i];
		for (int j = 0; str[j]; j++)
			str[j] = std::toupper(str[j]);
		std::cout << str;
	}
	std::cout << std::endl;
	return ;
}
