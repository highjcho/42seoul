/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:20:38 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/20 00:51:57 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _value;
		static const int _bits = 8;

	public:
		Fixed();
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& obj);
		~Fixed();

		Fixed(const int value);
		Fixed(const float float_value);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		bool operator<(const Fixed& obj);
		bool operator>=(const Fixed& obj);
		bool operator<=(const Fixed& obj);
		bool operator==(const Fixed& obj);
		bool operator!=(const Fixed& obj);



		Fixed& operator++(void);
		Fixed& operator--(void);
		const Fixed operator++(int);
		const Fixed operator--(int);

		static Fixed& min(Fixed& obj1, Fixed& obj2);
		static const Fixed& min(const Fixed& obj1, const Fixed& obj2);
		static Fixed& max(Fixed& obj1, Fixed& obj2);
		static const Fixed& max(const Fixed& obj1, const Fixed& obj2);
};

std::ostream& operator<<(std::ostream& ostream, const Fixed& obj);
bool operator>(const Fixed& obj1, const Fixed& obj2);
Fixed operator-(const Fixed& obj1, const Fixed& obj2);
Fixed operator+(const Fixed& obj1, const Fixed& obj2);
Fixed operator*(const Fixed& obj1, const Fixed& obj2);
Fixed operator/(const Fixed& obj1, const Fixed& obj2);


#endif