/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:40:48 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/17 15:02:10 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "easyfind.hpp"

int	main() {
	std::vector<int> v;
	std::vector<int>::iterator ret;

	for (int i = 0; i < 5; i++)
		v.push_back(i * 3);
	try {
		ret = easyfind(v, 6);
		std::cout << "Find target => vector[" << std::distance(v.begin(), ret) << "] : " << *ret << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		ret = easyfind(v, 1);
		std::cout << "Find target => vector[" << std::distance(v.begin(), ret) << "] : " << *ret << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}