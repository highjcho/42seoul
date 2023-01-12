/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:40:48 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/12 19:53:07 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "easyfind.hpp"

int	main() {
	std::vector<int> v;
	std::vector<int>::iterator ret;

	for (int i = 0; i < 5; i++)
		v.push_back(i);

	try {
		ret = easyfind(v, 3);
		std::cout << "Find target => " << *ret << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		ret = easyfind(v, 7);
		std::cout << "Find target => " << *ret << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}