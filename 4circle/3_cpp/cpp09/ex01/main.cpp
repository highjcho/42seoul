/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:00:24 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/17 15:11:05 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int main() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	

	std::vector<int> c;
	srand(time(NULL));
	Span span(10000);
	for (int i = 0; i < 10000; i++)
		span.addNumber(rand() % 10000);
	try {
		span.addNumber(1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "short span = " << span.shortestSpan() << std::endl;
	std::cout << "long span = " << span.longestSpan() << std::endl;

	Span span2(5);
	std::vector<int> arr;
	// span2.addNumber(1);
	for (int i = 0; i < 5; i++)
		arr.push_back(i);
	try {
		span2.addNumberInRange(arr.begin(), arr.end());
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "short span = " << span2.shortestSpan() << std::endl;
		std::cout << "long span = " << span2.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}