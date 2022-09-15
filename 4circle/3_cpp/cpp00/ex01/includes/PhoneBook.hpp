#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	private:
		int	idx;
		int	len;
		Contact contact[8];

	public:
		PhoneBook();
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