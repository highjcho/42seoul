/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:05:13 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/09 19:09:38 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : _idx(0) {
	std::cout << "이제 나는 생각할 수 있어!\n";
	for (int i = 0; i < MAX; i++)
		_ideas[i] = "";
}

Brain::Brain(const Brain &obj) {
	*this = obj;
}

Brain& Brain::operator=(const Brain &obj) {
	if (this != &obj) {
		for (int i = 0; i < MAX; i++)
			_ideas[i] = obj.getIdea(i);
		_idx = obj.getIdx();
	}
	return *this;
}

void Brain::setIdea(const std::string &idea) {
	_ideas[_idx] = idea;
	_idx++;
	if (_idx == MAX)
		_idx = 0;
}

std::string Brain::getIdea(int i) const{
	return _ideas[i];
}

int Brain::getIdx() const {
	return _idx;
}

Brain::~Brain() {
	std::cout << "이제 나는 생각할 수 없어..\n";
}