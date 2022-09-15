#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	idx = 0;
	len = 0;
}

void	PhoneBook::addContact() {
	std::string info[5];
	std::string msg[5] = {"First name: ", "Last name: ", "Nickname: ", "Phone number: ", "Darkest secret: "};
	int			i;

	std::cout << "\n======== Fill the contact information =======\n";
	for (i = 0; i < 5; i++) {
		std::cout << msg[i];
		if(!std::getline(std::cin, info[i])) {
			std::cout << "An error occurred in the input. Please try again.\n";
			std::cin.clear();
			i--;
		}
		if(info[i].compare("") == 0) {
			std::cout << "\n*Required* Please fill the information.\n\n";
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
		std::cout << "Error: There is no contact. Please add contact first\n";
		return ;
	}
	displayPhoneBook();
	std::cout << "Enter the index number(0 ~ " << len - 1 << "): ";
	std::cin >> search;
	std::cin.ignore();
	if (search < 0 || search >= len) {
		std::cout << "Error: Invalid number. Please try again\n";
		return ;
	}
	std::cout << "\n================== Contact [" << search << "] ==================\n";
	contact[search].displayAllInfo();
	std::cout << "=================================================\n";
	
}

void	PhoneBook::displayPhoneBook() {
	showContactTitle();
	for(int i = 0; i < len; i++) {
		contact[i].displayShortInfo(i);
	}
	std::cout << "=================================================\n";
}