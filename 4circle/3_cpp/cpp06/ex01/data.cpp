/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:38:01 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/11 13:44:55 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

int main() {
	Data origin;
	uintptr_t ptr;

	origin.data = "hello";
	std::cout << "origin.data = " << origin.data << ", origin addr = " << &origin << std::endl;
	ptr = serialize(&origin);
	Data* de = deserialize(ptr);
	std::cout << "de->data = " << de->data << ", de addr = " << de << std::endl;
}