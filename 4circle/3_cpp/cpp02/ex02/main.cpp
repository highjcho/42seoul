/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:02:10 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/20 15:41:48 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) { 
	Fixed a;
	Fixed const b(Fixed( 5.05f ) * Fixed( 2 ) );
	std::string ret;

	std::cout << "a : " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "a++ : " << a++ << std::endl;
	std::cout << "a : " << a << std::endl;

	std::cout << "b : " << b << std::endl;
	std::cout << "max - a ? b : " << Fixed::max(a, b) << std::endl;
	std::cout << "min - a ? b : " << Fixed::min(a, b) << std::endl;

	std::cout << "a > b : " << std::boolalpha << (a > b) << std::endl;
	std::cout << "a <= b : " << std::boolalpha << (a <= b) << std::endl;

	Fixed c(6);
	Fixed d(3);

	std::cout << "c : " << c << std::endl;
	std::cout << "d : " << d << std::endl;
	std::cout << "c + d : " << (c + d) << std::endl;
	std::cout << "c - d : " << (c - d) << std::endl;
	std::cout << "c * d : " << (c * d) << std::endl;
	std::cout << "c / d : " << (c / d) << std::endl;
	std::cout << "--c : " << --c << std::endl;
	std::cout << "c-- : " << c-- << std::endl;
	std::cout << "c : " << c << std::endl;


	return 0;
}