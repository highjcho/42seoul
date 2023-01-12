/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:47:08 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/12 19:54:25 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class NotFoundException : public std::exception {
	public:
		const char	*what() const throw() {
			return "Target is not in container";
		}
};

template <typename T>
typename T::iterator easyfind(T& container, int target) {
	typename T::iterator iter = std::find(container.begin(), container.end(), target);
	if (iter == container.end())
		throw NotFoundException();
	return iter;
};

#endif