/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:48:21 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/11 14:27:03 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

#include <iostream>
#include <ctime>

class Base {
	public:
		virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif