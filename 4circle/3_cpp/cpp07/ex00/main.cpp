/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:48:27 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/16 20:57:43 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "whatever.hpp"

int main() {
	int a = 2;
	int b = 3;
	swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string str1 = "chaine1";
	std::string str2 = "chaine2";
	swap(str1, str2);
	std::cout << "str1 = " << str1 << ", str2 = " << str2 << std::endl;
	std::cout << "min( str1, str2 ) = " << ::min( str1, str2 ) << std::endl;
	std::cout << "max( str1, str2 ) = " << ::max( str1, str2 ) << std::endl;

	a = 3;
	b = 10;
	int c = 5;
	int d = 5;

	std::cout << std::setw(20) << std::setfill('=') << " swap ";
	std::cout << std::setw(15) << std::setfill('=') << "\n";
	std::cout << "[before] a : " << a << ", b : " << b << " \n";
	swap(a, b);
	std::cout << "[after] a : " << a << ", b : " << b << std::endl;
	std::cout << std::setw(20) << std::setfill('=') << " min ";
	std::cout << std::setw(16) << std::setfill('=') << "\n";
	std::cout << "[result] a ? b : " << min(a, b) << std::endl;
	std::cout << "c addr = " << &c << ", d addr = " << &d;
	std::cout << "\n[result] c ? d : " << min(c, d) << ", addr = " << &(min(c, d)) << std::endl;
	std::cout << std::setw(20) << std::setfill('=') << " max ";
	std::cout << std::setw(16) << std::setfill('=') << "\n";
	std::cout << "[result] a ? b : " << max(a, b) << std::endl;
	std::cout << "d addr = " << &d << ", c addr = " << &c;
	std::cout << "\n[result] d ? c : " << max(d, c) << ", addr = " << &(max(d, c)) << std::endl;
	return (0);
}