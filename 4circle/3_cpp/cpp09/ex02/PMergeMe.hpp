/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:06:26 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/03/27 16:33:11 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMergeMe_HPP
# define PMergeMe_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ctime>

# define VECTOR "\033[0;32m"
# define LIST "\033[0;33m"
# define EOC "\033[0;0m"

class PMergeMe {
	private:
		int _size;
		std::vector<int> _vector;
		std::list<int> _list;
		clock_t _vStart;
		clock_t _vEnd;
		clock_t _lStart;
		clock_t _lEnd;

	public:
		PMergeMe();
		PMergeMe(const PMergeMe& obj);
		PMergeMe& operator=(const PMergeMe &obj);
		~PMergeMe();

		void makeVectorAndList(int len, char** av);

		void vectorInsertionSort(int left, int right);
		void mergeVector(int left, int mid, int right);
		void sortVector(int left, int right);

		void listInsertionSort(std::list<int>& lst);
		void mergeList(std::list<int>& left, std::list<int>& right);
		void sortList(std::list<int>& lst);

		std::vector<int> getVector() const;
		void setVectorStartTime();
		void setVectorEndTime();
		void printVectorTimeDiff() const;

		std::list<int>& getList();
		void setListStartTime();
		void setListEndTime();
		void printListTimeDiff() const;
};

#endif