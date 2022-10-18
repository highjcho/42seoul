/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:20:38 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/18 12:15:30 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int _value;
		static const int _bit = 8;

	public:
		Fixed();
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed& obj);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif