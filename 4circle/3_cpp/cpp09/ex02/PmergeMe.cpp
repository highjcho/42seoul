/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:59:31 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/04/19 13:29:45 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& obj) {
	*this = obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {
	if (this != &obj)
	{
		_vector = getVector();
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::makeVectorAndList(int size, char **av) {
	char *end;
	for (int i = 1; i < size; i++) {
		end = NULL;
		int num = std::strtod(av[i], &end);
		if (num < 0 || *end != '\0') {
			std::cout << "Error\n";
			exit(EXIT_FAILURE);
		}
		_vector.push_back(num);
		_list.push_back(num);
	}
	_size = size - 1;
	std::cout << "Before: ";
	printVector();
}

void PmergeMe::vectorInsertionSort(int left, int right) {
	int tmp;
	int i;
	int j;

	for (i = left + 1; i <= right; i++) {
		tmp = _vector[i];
		for (j = i - 1; j >= left && _vector[j] > tmp; j--)
			_vector[j + 1] = _vector[j];
		_vector[j + 1] = tmp;
	}
}

void PmergeMe::mergeVector(int left, int mid, int right) {
	std::vector<int> tmp;
	int i;
	int j;

	i = left;
	j = mid + 1;
	while (i <= mid && j <= right) {
		if (_vector[i] < _vector[j])
			tmp.push_back(_vector[i++]);
		else
			tmp.push_back(_vector[j++]);
	}
	while (i <= mid)
		tmp.push_back(_vector[i++]);
	while (j <= right)
		tmp.push_back(_vector[j++]);
	i = left;
	j = 0;
	while (i <= right)
		_vector[i++] = tmp[j++];
}

void PmergeMe::vectorMergeInsetionSort(int left, int right) {
	int n = right - left + 1;

	if (n < 15) {
		vectorInsertionSort(left, right);
		return ;
	}
	int mid = (left + right) / 2;
	vectorMergeInsetionSort(left, mid);
	vectorMergeInsetionSort(mid + 1, right);
	mergeVector(left, mid, right);
}

void PmergeMe::sortAndPrintVector() {
	setVectorStartTime();
	vectorMergeInsetionSort(0, _size - 1);
	setVectorEndTime();
	std::cout << VECTOR << "Vector After:" << EOC;
	printVector();
}

void PmergeMe::listInsertionSort(std::list<int>& lst) {
	int tmp;

	for (std::list<int>::iterator it = ++lst.begin(); it != lst.end(); ++it) {
		tmp = *it;
		std::list<int>::iterator j = it;
		j--;
		while (j != lst.begin() && *j > tmp) {
			*(std::next(j)) = *j;
			j--;
		}
		if (*j > tmp) {
			*(std::next(j)) = *j;
			*j = tmp;
		} else {
			*(std::next(j)) = tmp;
		}
	}
}

void PmergeMe::mergeList(std::list<int>& left, std::list<int>& right)
{
	std::list<int> tmp;
	std::list<int>::iterator i = left.begin();
	std::list<int>::iterator j = right.begin();

	while (i != left.end() && j != right.end()) {
		if (*i <= *j) {
			tmp.push_back(*i);
			i++;
		} else {
			tmp.push_back(*j);
			j++;
		}
	}
	while (i != left.end()) {
		tmp.push_back(*i);
		i++;
	}
	while (j != right.end()) {
		tmp.push_back(*j);
		j++;
	}
	left = tmp;
}

void PmergeMe::listMergeInsertionSort(std::list<int>& lst) {
	int n = lst.size();

	if (n < 15) {
		listInsertionSort(lst);
		return;
	}
	std::list<int>::iterator mid = lst.begin();
	std::advance(mid, n / 2);
	std::list<int> left(lst.begin(), mid);
	std::list<int> right(mid, lst.end());
	listMergeInsertionSort(left);
	listMergeInsertionSort(right);
	mergeList(left, right);
	lst = left;
}

void PmergeMe::sortAndPrintList() {
	setListStartTime();
	listMergeInsertionSort(_list);
	setListEndTime();
	std::cout << LIST << "List After:" << EOC;
	printList();
}

std::vector<int> PmergeMe::getVector() const {
	return _vector;
}

void PmergeMe::setVectorStartTime() {
	_vStart = clock();
}

void PmergeMe::setVectorEndTime() {
	_vEnd = clock();
}

void PmergeMe::printVector(){
	for (int i = 0; i < _size; i++)
		std::cout << " " << _vector[i];
	std::cout << "\n\n";
}

void PmergeMe::printVectorTimeDiff() const {
	double time = static_cast<double>(_vEnd - _vStart) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << _size << " elements with " << VECTOR << "std::[vector]: " << time << "ms" << EOC << std::endl;
}

std::list<int>& PmergeMe::getList() {
	return _list;
}

void PmergeMe::setListStartTime() {
	_lStart = clock();
}

void PmergeMe::setListEndTime() {
	_lEnd = clock();
}

void PmergeMe::printList() {
	std::list<int>::iterator it;
	for (it = _list.begin(); it != _list.end(); it++)
		std::cout << " " << *it;
		std::cout << "\n\n";
}

void PmergeMe::printListTimeDiff() const {
	double time = static_cast<double>(_lEnd - _lStart) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << _size << " elements with " << LIST << "std::[list]: " << time << "ms" << std::endl;
}