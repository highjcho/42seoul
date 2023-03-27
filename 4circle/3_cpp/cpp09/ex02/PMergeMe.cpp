#include "PMergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(const PMergeMe& obj) {
	*this = obj;
}

PMergeMe& PMergeMe::operator=(const PMergeMe& obj) {
	if (this != &obj)
	{
		_vector = getVector();
	}
	return (*this);
}

PMergeMe::~PMergeMe() {}

void PMergeMe::makeVectorAndList(int size, char **av) {
	std::cout << "Before:";
	for (int i = 1; i < size; i++) {
		int num = atoi(av[i]);
		if (num < 0 || (strcmp(av[i], "0") != 0 && num == 0)) {
			std::cout << "Error\n";
			exit(EXIT_FAILURE);
		}
		std::cout << " " << num;
		if (i == size - 1)
			std::cout << "\n\n";
		_vector.push_back(num);
		_list.push_back(num);
		_size = size - 1;
	}
}

void PMergeMe::vectorInsertionSort(int left, int right) {
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

void PMergeMe::mergeVector(int left, int mid, int right) {
	int tmp[right - left + 1];
	int i;
	int j;
	int k;

	i = 0;
	j = left;
	k = mid + 1;
	while (j <= mid && k <= right) {
		if (_vector[j] < _vector[k])
			tmp[i++] = _vector[j++];
		else
			tmp[i++] = _vector[k++];
	}
	while (j <= mid)
		tmp[i++] = _vector[j++];
	while (k <= right)
		tmp[i++] = _vector[k++];
	i = 0;
	j = left;
	while (j <= right)
		_vector[j++] = tmp[i++];
}

void PMergeMe::sortVector(int left, int right) {
	int n = right - left + 1;

	if (n < 11) {
		vectorInsertionSort(left, right);
		return ;
	}
	int mid = (left + right) / 2;
	sortVector(left, mid);
	sortVector(mid + 1, right);
	mergeVector(left, mid, right);
}

void PMergeMe::listInsertionSort(std::list<int>& lst) {
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

void PMergeMe::mergeList(std::list<int>& left, std::list<int>& right)
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

void PMergeMe::sortList(std::list<int>& lst) {
	int n = lst.size();

	if (n < 11) {
		listInsertionSort(lst);
		return;
	}
	std::list<int>::iterator mid = lst.begin();
	std::advance(mid, n / 2);
	std::list<int> left(lst.begin(), mid);
	std::list<int> right(mid, lst.end());
	sortList(left);
	sortList(right);
	mergeList(left, right);
	lst = left;
}

std::vector<int> PMergeMe::getVector() const {
	return _vector;
}

std::list<int>& PMergeMe::getList() {
	return _list;
}

void PMergeMe::setVectorStartTime() {
	_vStart = clock();
}

void PMergeMe::setVectorEndTime() {
	_vEnd = clock();
}

void PMergeMe::setListStartTime() {
	_lStart = clock();
}

void PMergeMe::setListEndTime() {
	_lEnd = clock();
}

void PMergeMe::printVectorTimeDiff() const {
	double time = _vEnd - _vStart;
	std::cout << "Time to process a range of " << _size << " elements with " << VECTOR << "std::[vector]: " << time << "ms" << EOC << std::endl;
}

void PMergeMe::printListTimeDiff() const {
	double time = _lEnd - _lStart;
	std::cout << "Time to process a range of " << _size << " elements with " << LIST << "std::[list]: " << time << "ms" << std::endl;
}
