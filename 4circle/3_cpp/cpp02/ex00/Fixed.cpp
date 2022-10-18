/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:20:40 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/18 12:16:30 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	_value = 0;
}

Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called\n";
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed& obj) {
	std::cout << "Copy assignment operator called\n";
	if (this != &obj)
		_value = obj.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}