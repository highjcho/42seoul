/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:19:03 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/10 15:56:56 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
: _name("default"), _flag(false), _sign(0), _execute(0)
{
	std::cout << "[Create] Default Form\n\n";
}

AForm::AForm(const std::string name, const int sign, const int execute)
: _name(name), _flag(false), _sign(sign), _execute(execute)
{
	if (_sign < MAX || _execute < MAX)
		throw AForm::GradeTooHighException();
	if (_sign > MIN || _execute > MIN)
		throw AForm::GradeTooLowException();
	std::cout << "[Create] " << FORM << _name << " AForm\n" << EOC;
}

AForm::AForm(const AForm& obj)
: _name(obj.getName()),  _flag(obj.getFlag()), _sign(obj.getSign()), _execute(obj.getExecute())
{
	if (_sign < MAX || _execute < MAX)
		throw AForm::GradeTooHighException();
	if (_sign > MIN || _execute > MIN)
		throw AForm::GradeTooLowException();
	std::cout << "[Create] " << FORM << " Copy AForm\n\n";
}

AForm& AForm::operator=(const AForm& obj) {
	if (this != &obj)
	{
		*(const_cast<std::string*>(&_name)) = obj.getName();
		_flag = obj.getFlag();
		*(const_cast<int*>(&_sign)) = obj.getSign();
		*(const_cast<int*>(&_execute)) = obj.getExecute();
		if (_sign < MAX || _execute < MAX)
			throw AForm::GradeTooHighException();
		if (_sign > MIN || _execute > MIN)
			throw AForm::GradeTooLowException();
	}
	return (*this);
}

void AForm::beSigned(const Bureaucrat& bureaucrat){
	if (_sign < bureaucrat.getGrade()) {
		_flag = false;
		throw GradeTooHighException();
	}
	_flag = true;
}

void AForm::checkExecute(const Bureaucrat& bureaucrat) const {
	if (!getFlag())
		throw AForm::RequiredSignException();
	if (getExecute() < bureaucrat.getGrade())
		throw AForm::GradeTooHighException();
}

const std::string& AForm::getName() const {
	return _name;
}

bool AForm::getFlag() const {
	return _flag;
}

const int& AForm::getSign() const {
	return _sign;
}

const int& AForm::getExecute() const {
	return _execute;
}

std::ostream& operator<<(std::ostream& o, const AForm& obj) {
	return o << FORM << "Name : " << obj.getName() << ", Flag : " << std::boolalpha << obj.getFlag()
		<< ", Sign_Grade : " << obj.getSign() << ", Execute_Grade : " << obj.getExecute() << "\n\n" << EOC;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "form Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "form Grade Too Low";
}

const char* AForm::RequiredSignException::what() const throw() {
	return "this form doesn't signed";
}

const char* AForm::FileErrorException::what() const throw() {
	return "a file error has occurred";
}

AForm::~AForm() {
	std::cout << "[Destroy] " << FORM << _name << " AForm\n\n" << EOC;
}