/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:59:39 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/04/21 13:19:20 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** av) {
	RPN rpn;
	
	if (ac != 2) {
		std::cout << "Error\n";
		exit(EXIT_FAILURE);
	}
	rpn.makeStack(av[1]);
	std::stack<int> stack = rpn.getFormular();
	if (stack.size() == 1)
		std::cout << stack.top() << std::endl;
	else
		std::cout << "Error\n";
}