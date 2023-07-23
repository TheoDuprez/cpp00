/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookClass.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:06:11 by tduprez           #+#    #+#             */
/*   Updated: 2023/07/23 21:38:09 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBookClass_HPP
# define PhoneBookClass_HPP

# include <iostream>
# include <cstdlib>

# define FIRSTNAME 1
# define LASTNAME 2
# define PHONENUMBER 3
# define SECRET 4

bool	isAllIsspace(std::string s);

class	Contact {

	public:

	Contact(void);
	~Contact(void);
	std::string	getData(int whichData) const;
	void		printData(int whichData) const;
	void		addContact(const char *prompt, int whichData);

	private:

	std::string	firstName;
	std::string	lastName;
	std::string	phoneNumber;
	std::string	secret;
};

class	PhoneBook {

	public:
	
	PhoneBook(void);
	~PhoneBook(void);
	Contact	contacts[8];

	private:

};

#endif
