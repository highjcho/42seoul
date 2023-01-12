/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:02:56 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/12 20:51:24 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
	private:
		std::vector<int> _span;
		unsigned int _size;
		Span();

	public:
		Span(unsigned int n);
		Span(const Span& obj);
		Span& operator=(const Span &obj);
		~Span();

		void addNumber(int n);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		unsigned int getSize() const;
		std::vector<int> getSpan() const;

		class FullContainerException : public std::exception {
			public:
				const char *what() const throw();
		};
		class NotEnoughException : public std::exception {
			public:
				const char *what() const throw();
		};
};

#endif