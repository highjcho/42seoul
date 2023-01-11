/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:04:54 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/11 14:29:10 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void) {
	srand(time(NULL));
	switch (rand() % 3) {
	case 0:
		std::cout << "Generate A\n";
		return new A();
	case 1:
		std::cout << "Generate B\n";
		return new B();
	case 2:
		std::cout << "Generate C\n";
		return new C();
	default:
		std::cerr << "Error\n";
	}
	return (NULL);
}

void identify(Base* p) {
	std::cout << "P : ";
	if (dynamic_cast<A*>(p))
		std::cout << "\"A\"\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "\"B\"\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "\"C\"\n";
	else
		std::cout << "none of \"A, B, C\"\n";
}

void identify(Base& p) {
	std::cout << "ref P : ";
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "\"A\"\n";
		static_cast<void>(a);
		return ;
	} catch (std::exception &e) {}
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "\"B\"\n";
		static_cast<void>(b);
		return ;
	} catch (std::exception &e) {}
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "\"C\"\n";
		static_cast<void>(c);
	} catch (std::exception &e) {
		std::cout << "none of \"A, B, C\"\n";
	}
}