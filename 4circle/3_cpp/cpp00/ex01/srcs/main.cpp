/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:13:39 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/09/29 13:33:27 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
	PhoneBook	phoneBook;
	std::string	cmd;
	int			result;

	result = 1;
	while(result) {
		std::cout << "Type a command [ADD (add) | SEARCH (search) | EXIT (exit)] ==> ";
		if(!std::getline(std::cin >> std::ws, cmd) || std::cin.eof()) {
			if (std::cin.eof()) {
				std::cout << "\nEOF: Goodbye~!\n";
				break;
			}
			std::cout << "\nAn error occurred in the input. Please try again.\n";
			std::cin.clear();
			std::cin.ignore(4096, '\n');
			continue;
		}
		result = phoneBook.inputCommand(cmd);
	}
	return (0);
}