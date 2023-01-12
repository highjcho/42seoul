/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:15:55 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/12 16:01:38 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void iter(T* addr, size_t len, void (*f_ptr)(const T& elements)) {
	for (size_t i = 0; i < len; i++)
		f_ptr(addr[i]);
}