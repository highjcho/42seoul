/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:06:19 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/12 16:22:09 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(const T& element) {
	std::cout << element << std::endl;
}

int main() {
	int num_arr[5] = {3, 5, 7, 9, 10};
	std::string str_arr[5] = {"mu", "samsak", "yatong", "gilmak", "ddongddang"};

	std::cout << "1. num_arr\n";
	iter(num_arr, 5, print);
	std::cout << "2. str_arr\n";
	iter(str_arr, 5, print);
}