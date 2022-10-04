/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:56:35 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/04 15:24:01 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int main(void) {
	std::string original = "HI THIS IS BRAIN";
	std::string* stringPTR = &original;
	std::string& stringREF = original;

	std::cout << "==========[ADDRESS]=========\n";
	std::cout << "1. original : " << &original << std::endl;
	std::cout << "2. stringPTR: " << &stringPTR << std::endl;
	std::cout << "3. stringREF: " << &stringREF << std::endl;
	std::cout << std::setw(30) << std::setfill('=') << "\n\n";

	std::cout << "============[VALUE]============\n";
	std::cout << "1. original : " << original << std::endl;
	std::cout << "2. stringPTR: " << stringPTR << std::endl;
	std::cout << "3. stringREF: " << stringREF << std::endl;
	std::cout << std::setw(33) << std::setfill('=') << "\n\n";
}