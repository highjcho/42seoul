/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:30:14 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/09 15:11:11 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug() {
	std::cout << "[debug]: I think that I typed 'rm -rf'\n";
}

void Harl::info() {
	std::cout << "[info]: I was actually trying to type 'rm *.o'\n";
}

void Harl::warning() {
	std::cout << "[warning]: What?? I can't go back???\n";
}

void Harl::error() {
	std::cout << "[error]: NO. I NEED TO GET IT BACK!\n";
}

void Harl::complain(const std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*f_ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*f_ptr[i])();
			break;
		}
	}
}