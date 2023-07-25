/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:06:11 by tduprez           #+#    #+#             */
/*   Updated: 2023/07/25 14:21:39 by tduprez          ###   ########lyon.fr   */
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

class	PhoneBook
{

	public:
	
	PhoneBook(void);
	~PhoneBook(void);
	Contact&	getContacts(const int index);

	private:
	Contact _contacts[8];

};

bool	isAllIsspace(std::string s);
void	addContact(PhoneBook& repertory, int index);
void	searchContact(PhoneBook& repertory);

#endif
