/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:02:58 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/13 12:39:17 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat mu = Bureaucrat("mu", 2);
		std::cout << mu;
	} catch (std::exception& e) {
		std::cerr << ERR << e.what() << "\n\n" << EOC;
	}

	try {
		Bureaucrat samsak = Bureaucrat("samsak", 153);
		std::cout << samsak;
	} catch (std::exception& e) {
		std::cerr << ERR << e.what() << "\n\n" << EOC;
	}

	Bureaucrat mu("mu", 1);
	Bureaucrat samsak("samsak", 150);

	try {
		mu.increment();
		std::cout << mu;
	} catch (std::exception& e) {
		std::cerr << ERR << e.what() << "\n\n" << EOC;
	}

	try {
		samsak.decrement();
		std::cout << samsak;
	} catch (std::exception& e) {
		std::cerr << ERR << e.what() << "\n\n" << EOC;
	}

	try {
		mu.decrement();
		std::cout << mu;
	} catch (std::exception& e) {
		std::cerr << ERR << e.what() << "\n\n" << EOC;
	}

	try {
		samsak.increment();
		std::cout << samsak;
	} catch (std::exception& e) {
		std::cerr << ERR << e.what() << "\n\n" << EOC;
	}
}
