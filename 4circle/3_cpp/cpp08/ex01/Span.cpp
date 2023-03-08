/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:18:16 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/17 15:12:04 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _container(0), _size(0) {}

Span::Span(unsigned int n) : _container(0), _size(n) {}

Span::Span(const Span& obj) {
	*this = obj;
}

Span& Span::operator=(const Span& obj) {
	if (this != &obj)
	{
		_container = obj.getContainer();
		_size = obj.getSize();
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int n) {
	if (_container.size() == _size)
		throw FullContainerException();
	_container.push_back(n);
}

void Span::addNumberInRange(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end) {
	if (std::distance(begin, end) > static_cast<int>(_size - _container.size()))
		throw FullContainerException();
	for (std::vector<int>::iterator it = begin; it != end; it++)
		_container.push_back(*it);
}

unsigned int Span::shortestSpan() const {
	if (_container.size() < 2)
		throw NotEnoughException();
	std::vector<int> tmp = _container;
	std::sort(tmp.begin(), tmp.end());
	std::vector<int>::iterator iter = tmp.begin();
	int ret = INT_MAX;
	while (iter != tmp.end() - 1) {
		ret = std::min(ret, *(iter + 1) - *iter);
		iter++;
	}
	return ret;
}

unsigned int Span::longestSpan() const {
	if (_container.size() < 2)
		throw NotEnoughException();
	std::vector<int> tmp = _container;
	std::sort(tmp.begin(), tmp.end());
	return tmp.back() - tmp.front();
}

std::vector<int> Span::getContainer() const {
	return _container;
}

unsigned int Span::getSize() const {
	return _size;
}

const char* Span::FullContainerException::what() const throw() {
	return "Container is full";
}

const char* Span::NotEnoughException::what() const throw() {
	return "Container size is not enough to execute";
}

