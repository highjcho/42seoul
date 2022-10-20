/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:20:40 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/20 20:53:21 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	_value = 0;
}

Fixed::Fixed(const Fixed &obj) {
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed& obj) {
	if (this != &obj)
		_value = obj.getRawBits();
	return *this;
}

Fixed::~Fixed() {
}

Fixed::Fixed(const int value) {
	_value = value << _bits;
}

Fixed::Fixed(const float value) {
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

bool operator>(const Fixed& obj1, const Fixed& obj2) {
	return obj1.getRawBits() > obj2.getRawBits();
}

bool Fixed::operator<(const Fixed& obj) {
	return _value < obj.getRawBits();
}

bool Fixed::operator>=(const Fixed& obj) {
	return _value >= obj.getRawBits();
}

bool Fixed::operator<=(const Fixed& obj) {
	return _value <= obj.getRawBits();
}

bool operator==(const Fixed& obj1, const Fixed& obj2) {
	return obj1.getRawBits() == obj2.getRawBits();
}

bool Fixed::operator!=(const Fixed& obj) {
	return _value != obj.getRawBits();
}

Fixed operator+(const Fixed& obj1, const Fixed& obj2) {
	return Fixed(obj1.toFloat() + obj2.toFloat());
}

Fixed operator-(const Fixed& obj1, const Fixed& obj2) {
	return Fixed(obj1.toFloat() - obj2.toFloat());
}

Fixed operator*(const Fixed& obj1, const Fixed& obj2) {
	return Fixed(obj1.toFloat() * obj2.toFloat());
}

Fixed operator/(const Fixed& obj1, const Fixed& obj2) {
	return Fixed(obj1.toFloat() / obj2.toFloat());
}

Fixed& Fixed::operator++(void) {
	this->_value += 1;
	return *this;
}

Fixed& Fixed::operator--(void) {
	this->_value -= 1;
	return *this;
}

const Fixed Fixed::operator++(int) {
	Fixed ret(*this);

	this->_value += 1;
	return ret;
}

const Fixed Fixed::operator--(int) {
	Fixed ret(*this);

	this->_value -= 1;
	return ret;
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2) {
	if (obj1 <= obj2)
		return obj1;
	return obj2;
}

const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2) {
	if (obj1.getRawBits() <= obj2.getRawBits())
		return obj1;
	return obj2;
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2) {
	if (obj1 >= obj2)
		return obj1;
	return obj2;
}

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2) {
	if (obj1.getRawBits() >= obj2.getRawBits())
		return obj1;
	return obj2;
}