/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:13:26 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/09/28 19:22:12 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cctype>
#include "Contact.hpp"

class PhoneBook {
	private:
		int	idx;
		int	len;
		Contact contact[8];

	public:
		PhoneBook();
		int		inputCommand(std::string cmd);
		void	addContact();
		void	searchContact();
		void	displayPhoneBook();
		void	showContactTitle() const {
			std::cout << "\n************** HYUNJCHO's PHONEBOOK *************\n\n";
			std::cout << "=================================================\n";
			std::cout << std::setw(MAX_WIDTH) << "INDEX" << "| " \
				<< std::setw(MAX_WIDTH) << "FIRST NAME" << "| " \
				<< std::setw(MAX_WIDTH) << "LAST NAME" << "| " \
				<< std::setw(MAX_WIDTH) << "NICKNAME" << "\n";
		}
};

#endif