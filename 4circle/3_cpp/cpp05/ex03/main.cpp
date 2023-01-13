/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:02:58 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/13 13:07:17 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	Bureaucrat mu = Bureaucrat("mu", 2);
	Intern intern = Intern();

	std::cout << mu;

	try {
		AForm* form = intern.makeForm(R_NAME, "transfomer");
		std::cout << *form;
		mu.signForm(*form);
		std::cout << *form;
		delete form;
	} catch (std::exception& e) {
		std::cerr << "Intern can't make form because " << ERR << e.what() << "\n\n";
	}

	try {
		AForm* form = intern.makeForm("noform", "error");
		std::cout << *form;
		mu.signForm(*form);
		std::cout << *form;
		delete form;
	} catch (std::exception& e) {
		std::cerr << "Intern can't make form because " << ERR << e.what() << "\n\n" << EOC;
	}
}
