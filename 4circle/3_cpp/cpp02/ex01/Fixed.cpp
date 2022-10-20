/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:20:40 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/20 17:51:01 by hyunjcho         ###   ########.fr       */
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

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called\n";
	_value = value << _bits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called\n";
	_value = roundf(value * (1 << _bits));
}

int Fixed::getRawBits() const {
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(_value) / (1 << _bits);
}

int Fixed::toInt() const {
	return _value >> _bits;
}

std::ostream& operator<<(std::ostream& ostream, const Fixed& obj)
{
	return ostream << obj.toFloat();
}