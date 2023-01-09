/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:30:59 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/06 22:19:41 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "You can't call this\n";
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
		*(const_cast<std::string*>(&_name)) = obj.getName(); // const cast 더 알아보기
		_grade = obj.getGrade();
	}
	return *this;
};

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

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

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "[Error] Bureaucrat Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "[Error] Bureaucrat Grade Too Low";
}

Bureaucrat::~Bureaucrat() {
	std::cout << "[Destroy] Bureaucrat\n\n";
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& obj) {
	return o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "\n\n";
}