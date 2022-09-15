#include "PhoneBook.hpp"

int main() {
	PhoneBook phoneBook;

	while(1) {
		std::string cmd;

		std::cout << "What would you like? ==> ";
		std::cin >> cmd;
		std::cin.ignore();
		if (cmd.compare("ADD") == 0) 
			phoneBook.addContact();
		else if (cmd.compare("SEARCH") == 0) 
			phoneBook.searchContact();
		else if (cmd.compare("EXIT") == 0) {
			std::cout << "\nGoodbye~!";
			exit(EXIT_SUCCESS);
		}
		else
			std::cout << "Usage: ADD, SEARCH, EXIT\n";
	}
}