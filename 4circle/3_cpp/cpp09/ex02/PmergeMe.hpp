/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:25:46 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/04/21 13:35:05 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>

# define VECTOR "\033[0;32m"
# define LIST "\033[0;33m"
# define EOC "\033[0;0m"

class PmergeMe {
	private:
		int _size;
		std::vector<int> _vector;
		std::list<int> _list;
		clock_t _vStart;
		clock_t _vEnd;
		clock_t _lStart;
		clock_t _lEnd;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& obj);
		PmergeMe& operator=(const PmergeMe &obj);
		~PmergeMe();

		void makeVectorAndList(int len, char** av);

		void vectorInsertionSort(int left, int right);
		void mergeVector(int left, int mid, int right);
		void vectorMergeInsetionSort(int left, int right);
		void sortAndPrintVector();

		void listInsertionSort(std::list<int>& lst);
		void mergeList(std::list<int>& left, std::list<int>& right);
		void listMergeInsertionSort(std::list<int>& lst);
		void sortAndPrintList();

		void setVectorStartTime();
		void setVectorEndTime();
		void printVector();
		void printVectorTimeDiff() const;

		void setListStartTime();
		void setListEndTime();
		void printList();
		void printListTimeDiff() const;
};

#endif