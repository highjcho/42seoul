/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:19:50 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/13 17:30:21 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
	Base* a = new A();
	Base* b = new B();
	Base* c = new C();
	Base* base = new Base();

	Base* gen1 = generate();
	identify(gen1);
	identify(a);
	identify(b);
	identify(c);
	identify(base);
	identify(*a);
	identify(*b);
	identify(*c);
	identify(*base);
}