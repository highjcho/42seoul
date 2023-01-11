/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:30:59 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/11 16:00:25 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

Bureaucrat::~Bureaucrat() {
	std::cout << "[Destroy] " << "Bureaucrat\n\n";
};

void Bureaucrat::signForm(const AForm& form) const {
	try {
		(*const_cast<AForm*>(&form)).beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "\n\n";
	} catch (std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " becasue ";
		std::cerr << ERR << e.what() << "\n\n" << EOC;
	}
}

void Bureaucrat::executeForm(const AForm& form) const {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << "\n\n";
	} catch (std::exception& e) {
		std::cout << _name << " couldn't execute " << form.getName() << " because ";
		std::cerr << ERR << e.what() << "\n\n" << EOC;
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
	return "bureaucrat grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "bureaucrat grade too low";
}