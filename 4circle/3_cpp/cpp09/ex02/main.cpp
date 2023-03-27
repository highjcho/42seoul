/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:15:04 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/03/27 16:32:47 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#include <iomanip>

int main(int ac, char** av) {

	if (ac < 2) {
		std::cout << "usage: ./PMergeMe [numbers]\n";
		exit(EXIT_FAILURE);
	}
	PMergeMe sort;
	sort.makeVectorAndList(ac, av);
	sort.setVectorStartTime();
	sort.sortVector(0, ac - 2);
	sort.setVectorEndTime();
	std::vector<int> vector = sort.getVector();
	std::cout << VECTOR << "Vector After:" << EOC;
	for (int i = 0; i < ac - 1; i++)
		std::cout << " " << vector[i];
	std::cout << "\n\n";
	sort.setListStartTime();
	std::list<int>& list = sort.getList();
	sort.sortList(list);
	sort.setListEndTime();
	std::cout << LIST << "List After:" << EOC;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << " " << *it;
	std::cout << "\n\n";
	sort.printVectorTimeDiff();
	sort.printListTimeDiff();
}