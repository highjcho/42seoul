/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:32:04 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/14 18:46:01 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string upperLevel(std::string level) {
	for (size_t i = 0; i < level.size(); i++)
		level[i] = toupper(level[i]);
	return level;
}

int main(int ac, char **av) {
	Harl harl;
	if (ac != 2) {
		std::cout << "Usage: ./harlFilter LEVEL (DEBUG, INFO, WARNING, ERROR)\n";
		exit(EXIT_FAILURE);
	}
	std::string level = upperLevel(av[1]);
	harl.harlFilter(level);
	exit(EXIT_SUCCESS);
}