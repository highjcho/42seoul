/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:30:14 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/07 17:30:28 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug() {
	std::cout << "[ DEBUG ]\n";
	std::cout << "I think that I typed 'rm -rf'\n\n";
}

void Harl::info() {
	std::cout << "[ INFO ]\n";
	std::cout << "I was actually trying to type 'rm -o.*'\n\n";
}

void Harl::warning() {
	std::cout << "[ WARNING ]\n";
	std::cout << "What?? I can't go back???\n\n";
}

void Harl::error() {
	std::cout << "[ ERROR ]\n";
	std::cout << "NO. I NEED TO GET IT BACK!\n\n";
}

void Harl::harlFilter(std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*f_ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i;

	for (i = 0; i < 4; i++) {
		if (levels[i] == level) {
			break;
		}
	}
	switch(i) {
		case 0:
			(this->*f_ptr[0])();
		case 1:
			(this->*f_ptr[1])();
		case 2:
			(this->*f_ptr[2])();
		case 3:
			(this->*f_ptr[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}