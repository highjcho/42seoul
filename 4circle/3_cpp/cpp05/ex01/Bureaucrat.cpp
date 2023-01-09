/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:30:59 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/09 20:11:36 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void Bureaucrat::signForm(const Form& form) const{
	try {
		(*const_cast<Form*>(&form)).beSigned(*this); // 왜왜뜨냐~
		std::cout << _name << " signed " << form.getName();
	} catch (std::exception e) {
		std:: cout << _name << " couldn't sign " << form.getName() << " becasue " << e.what() << "\n\n";
	}
}

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

std::ostream& operator<<(std::ostream& o, const Bureaucrat& obj) {
	return o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "\n\n";
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