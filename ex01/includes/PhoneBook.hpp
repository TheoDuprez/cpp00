/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:06:11 by tduprez           #+#    #+#             */
/*   Updated: 2023/07/24 17:06:34 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstdlib>
# include "./Contact.hpp"

# define FIRSTNAME 1
# define LASTNAME 2
# define NICKNAME 3
# define PHONENUMBER 4
# define SECRET 5

class	PhoneBook {

	public:
	
	PhoneBook(void);
	~PhoneBook(void);
	Contact	contacts[8];

	private:

};

bool	isAllIsspace(std::string s);
void	addContact(PhoneBook& repertory, int index);
void	searchContact(PhoneBook& repertory);

#endif
