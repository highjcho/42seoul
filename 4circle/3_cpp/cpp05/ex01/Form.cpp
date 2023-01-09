/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:16:58 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/09 20:12:33 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
: _name("default"), _flag(false), _sign(0), _execute(0)
{
	std::cout << "[Create] Default Form\n\n";
}

Form::Form(const std::string name, const int sign, const int execute)
: _name(name), _flag(false), _sign(sign), _execute(execute)
{
	if (_sign < MAX || _execute < MAX)
		throw GradeTooHighException();
	if (_sign > MIN || _execute > MIN)
		throw GradeTooLowException();
	std::cout << "[Create] " << _name << " Form\n\n";
}

Form::Form(const Form& obj)
: _name(obj.getName()),  _flag(obj.getFlag()), _sign(obj.getSign()), _execute(obj.getExecute())
{
	if (_sign < MAX || _execute < MAX)
		throw GradeTooHighException();
	if (_sign > MIN || _execute > MIN)
		throw GradeTooLowException();
	std::cout << "[Create] Copy Form\n\n";
}

Form& Form::operator=(const Form& obj) {
	if (this != &obj)
	{
		*(const_cast<std::string*>(&_name)) = obj.getName();
		_flag = obj.getFlag();
		*(const_cast<int*>(&_sign)) = obj.getSign();
		*(const_cast<int*>(&_execute)) = obj.getExecute();
		if (_sign < MAX || _execute < MAX)
			throw GradeTooHighException();
		if (_sign > MIN || _execute > MIN)
			throw GradeTooLowException();
	}
	return (*this);
}

void Form::beSigned(const Bureaucrat& bureaucrat){
	if (_sign >= bureaucrat.getGrade())
		_flag = true;
	else
		throw GradeTooLowException();
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
	return o << "Name : " << obj.getName() << ", Flag : " << obj.getFlag()
		<< ", Sign_Grade : " << obj.getSign() << ", Execute_Grade : " << obj.getExecute() << "\n\n";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "[Error] Bureaucrat Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "[Error] Bureaucrat Grade Too Low";
}

Form::~Form() {
	std::cout << "[Destroy] " << _name << " Form\n\n";
}

