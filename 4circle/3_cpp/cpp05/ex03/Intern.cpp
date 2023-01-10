/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:17:04 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/10 18:15:10 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "[Create] Intern\n\n";
}

Intern::Intern(const Intern& obj){
	*this = obj;
}

Intern&	Intern::operator=(const Intern& obj){
	(void)obj;
	return (*this);
}

Intern::~Intern() {
	std::cout << "[Destroy] Intern\n\n";
}

AForm* Intern::makeForm(const std::string& form, const std::string& target) {
	std::string forms[3] = {S_NAME, R_NAME, P_NAME};
	
	for (int i = 0; i < 3; i++) {
		if (forms[i] == form) {
			std::cout << "Intern make " << form << " form\n\n";
			switch (i) {
				case 0:
					return new ShrubberyCreationForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new PresidentialPardonForm(target);
			}
		}
	}
	throw NoFormException();

}

const char* Intern::NoFormException::what() const throw() {
	return "there is no such form";
}