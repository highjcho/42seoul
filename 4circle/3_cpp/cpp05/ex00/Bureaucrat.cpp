/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:30:59 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/11 15:46:47 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: _name("default"), _grade(100)
{
	std::cout << "[Create] " << *this;
};

Bureaucrat::Bureaucrat(const std::string& name, int const grade)
: _name(name), _grade(grade)
{
	if (_grade < MAX)
		throw GradeTooHighException();
	if (_grade > MIN)
		throw GradeTooLowException();
	std::cout << "[Create] " << *this;
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj) {
	*this = obj;
};

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &obj) {
	if (this != &obj) {
		*(const_cast<std::string*>(&_name)) = obj.getName();
		_grade = obj.getGrade();
	}
	return *this;
};

Bureaucrat::~Bureaucrat() {
	std::cout << "[Destroy] Bureaucrat\n\n";
};

void Bureaucrat::increment() {
	if (_grade - 1 < MAX)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrement() {
	if (_grade + 1 > MIN)
		throw GradeTooLowException();
	_grade++;
}

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& obj) {
	return o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "\n\n";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "bureaucrat grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "bureaucrat grade too low";
}