/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:16:58 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/13 12:45:41 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
: _name("default"), _flag(false), _sign(100), _execute(100) {}

Form::Form(const std::string name, const int sign, const int execute)
: _name(name), _flag(false), _sign(sign), _execute(execute)
{
	if (_sign < HIGH || _execute < HIGH)
		throw GradeTooHighException();
	if (_sign > LOW || _execute > LOW)
		throw GradeTooLowException();
}

Form::Form(const Form& obj)
: _name(obj.getName()),  _flag(obj.getFlag()), _sign(obj.getSign()), _execute(obj.getExecute())
{
	if (_sign < HIGH || _execute < HIGH)
		throw GradeTooHighException();
	if (_sign > LOW || _execute > LOW)
		throw GradeTooLowException();
}

Form& Form::operator=(const Form& obj) {
	if (this != &obj)
	{
		*(const_cast<std::string*>(&_name)) = obj.getName();
		_flag = obj.getFlag();
		*(const_cast<int*>(&_sign)) = obj.getSign();
		*(const_cast<int*>(&_execute)) = obj.getExecute();
		if (_sign < HIGH || _execute < HIGH)
			throw GradeTooHighException();
		if (_sign > LOW || _execute > LOW)
			throw GradeTooLowException();
	}
	return (*this);
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat& bureaucrat){
	if (_sign < bureaucrat.getGrade()) {
		_flag = false;
		throw GradeTooLowException();
	}
	_flag = true;
}

const std::string& Form::getName() const {
	return _name;
}

bool Form::getFlag() const {
	return _flag;
}

const int& Form::getSign() const {
	return _sign;
}

const int& Form::getExecute() const {
	return _execute;
}

std::ostream& operator<<(std::ostream& o, const Form& obj) {
	return o << "[Form] Name : " << obj.getName() << ", Flag : " << std::boolalpha << obj.getFlag()
		<< ", Sign_Grade : " << obj.getSign() << ", Execute_Grade : " << obj.getExecute() << "\n\n";
}

const char* Form::GradeTooHighException::what() const throw() {
	return "grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "grade too low";
}