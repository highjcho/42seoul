/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:01:59 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/16 21:42:42 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

#include <iostream>

template <typename T>
void swap(T& t1, T& t2) {
	T tmp;

	tmp = t1;
	t1 = t2;
	t2 = tmp;
}

template <typename T>
const T& min(const T& t1, const T& t2) {
	return t1 < t2 ? t1 : t2;
}

template <typename T>
const T& max(const T& t1, const T& t2) {
	return t1 > t2 ? t1 : t2;
}

#endif