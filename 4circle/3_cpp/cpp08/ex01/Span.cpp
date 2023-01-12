/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:18:16 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/12 20:57:01 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _span(0, 0), _size(0) {}

Span::Span(unsigned int n) : _span(0, 0), _size(n) {}

Span::Span(const Span& obj) {
	*this = obj;
}

Span& Span::operator=(const Span& obj) {
	if (this != &obj)
	{
		_span = obj.getSpan();
		_size = obj.getSize();
	}
	return (*this);
}

void Span::addNumber(int n) {
	if (_span.size() == _size)
		throw FullContainerException();
	_span.push_back(n);
}

unsigned int Span::shortestSpan() const {
	if (_span.size() < 2)
		throw NotEnoughException();
	std::vector<int> tmp = _span;
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
	if (_span.size() < 2)
		throw NotEnoughException();
	std::vector<int> tmp = _span;
	std::sort(tmp.begin(), tmp.end());
	return tmp.back() - tmp.front();
}

std::vector<int> Span::getSpan() const {
	return _span;
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

Span::~Span() {}