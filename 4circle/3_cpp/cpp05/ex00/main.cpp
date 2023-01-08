/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:02:58 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/06 22:18:20 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat mu = Bureaucrat("mu", 2);
	} catch (std::exception& e) { // e는 참조형으로 받아야 함
		std::cerr << e.what() << "\n\n";
	}

	try {
		Bureaucrat samsak = Bureaucrat("samsak", 153);
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n\n";
	}

	Bureaucrat mu("mu", 1);
	Bureaucrat samsak("samsak", 150);

	try {
		mu.increment();
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n\n";
	}

	try {
		samsak.decrement();
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n\n";
	}

	try {
		mu.decrement();
		std::cout << mu;
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n\n";
	}

	try {
		samsak.increment();
		std::cout << samsak;
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n\n";
	}
}