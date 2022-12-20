/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:13:42 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/20 11:21:12 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	idx = 0;
	len = 0;
}

int	PhoneBook::inputCommand(std::string cmd) {
	unsigned long	i;

	for (i = 0; i < cmd.size(); i++)
		cmd[i] = toupper(cmd[i]);
	if (cmd == "ADD") 
		addContact();
	else if (cmd == "SEARCH") 
		searchContact();
	else if (cmd == "EXIT") {
		std::cout << "\nGoodbye~!\n";
		return (0);
	}
	else
		std::cout << "\nError: \"" << cmd << "\" Invaild command. <Usage: ADD, SEARCH, EXIT>\n\n";
	return (1);
}

void	PhoneBook::addContact() {
	std::string info[5];
	std::string msg[5] = {"First name: ", "Last name: ", "Nickname: ", "Phone number: ", "Darkest secret: "};
	int			i;

	std::cout << "\n======== Fill the contact information =======\n";
	for (i = 0; i < 5; i++) {
		std::cout << msg[i];
		if(!std::getline(std::cin, info[i]) || std::cin.eof()) {
			if (std::cin.eof()) {
				std::cout << "\nEOF: The information has not been saved. Phonebook is closed.\n\n"; 
				exit(EXIT_SUCCESS);
			}
			std::cout << "\nAn error occurred in the input. Please try again.\n";
			std::cin.clear();
			std::cin.ignore(4096, '\n');
			i--;
			continue;
		}
		if(info[i] == "") {
			std::cout << "\n*Required* Please fill the imnformation.\n\n";
			i--;
		}
	}
	std::cout << "==============================================\n\n";
	PhoneBook::contact[idx] = Contact(info[0], info[1], info[2], info[3], info[4]);
	idx++;
	if (idx == 8)
		idx = 0;
	if (len != 8)
		len++;
}

void	PhoneBook::searchContact() {
	int	search;

	if (len < 1) {
		std::cout << "\nError: There is no contact. Please add contact first.\n\n";
		return ;
	}
	while (true) {
		displayPhoneBook();
		std::cout << "Enter the index number(0 ~ " << len - 1 << "): ";
		std::cin >> search;
		if (std::cin.eof())
			return ;
		if (std::cin.fail() || search < 0 || search >= len) {
			std::cout << "\nAn error occurred in the input. Please try again.\n";
			std::cin.clear();
			std::cin.ignore(4096, '\n');
			continue;
		}
		break;
	}
	std::cout << "\n================== Contact [" << search << "] ==================\n";
	contact[search].displayAllInfo();
	std::cout << "=================================================\n\n";
}

void	PhoneBook::displayPhoneBook() {
	showContactTitle();
	for(int i = 0; i < len; i++) {
		contact[i].displayShortInfo(i);
	}
	std::cout << "=================================================\n\n";
}