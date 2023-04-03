/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:15:04 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/04/03 19:49:34 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>

int main(int ac, char** av) {
	if (ac < 2) {
		std::cout << "usage: ./PMergeMe [numbers]\n";
		exit(EXIT_FAILURE);
	}
	PmergeMe sort;
	sort.makeVectorAndList(ac, av);
	sort.sortAndPrintVector();
	sort.sortAndPrintList();
	sort.printVectorTimeDiff();
	sort.printListTimeDiff();
}