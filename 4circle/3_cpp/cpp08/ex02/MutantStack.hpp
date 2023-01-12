/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:22:11 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/12 21:56:36 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() {}
	MutantStack(const MutantStack &origin) { *this = origin; }
	MutantStack &operator=(const MutantStack &origin) {
		if (this != &origin)
			std::stack<T>::opertator=(origin);
		return (*this);
	}
	~MutantStack() {}
	
	typedef typename MutantStack<T>::stack::container_type::iterator iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
	const_iterator cbegin() const { return this->c.cbegin(); }
	const_iterator cend() const { return this->c.cbegin(); }

	typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator crbegin() const { return this->c.rbegin(); }
	const_reverse_iterator crend() const { return this->c.crend(); }
};

#endif