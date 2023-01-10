/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:02:58 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/10 16:56:06 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat mu = Bureaucrat("mu", 2);
	Bureaucrat samsak = Bureaucrat("samsak", 139);
	Bureaucrat yatong = Bureaucrat("yatong", 148);

	AForm* moon = new ShrubberyCreationForm("Moon");
	mu.signForm(*moon);
	std::cout << "[Form info] " << *moon;
	mu.executeForm(*moon);
	samsak.signForm(*moon);
	std::cout << "[Form info] " << *moon;
	samsak.executeForm(*moon);
	yatong.signForm(*moon);
	std::cout << "[Form info] " << *moon;
	yatong.executeForm(*moon);
	delete moon;

	AForm* robot = new RobotomyRequestForm("transfomer");
	mu.signForm(*robot);
	mu.executeForm(*robot);

	AForm* where42 = new PresidentialPardonForm("where42");
	mu.signForm(*where42);
	mu.executeForm(*where42);
	delete where42;
}
