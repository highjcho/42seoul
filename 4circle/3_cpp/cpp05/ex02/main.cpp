/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:02:58 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/13 13:17:19 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

# define BUREAUCRAT "\033[1;30m"
# define SHRUBBERY "\033[1;32m"
# define ROBOT "\033[1;36m"
# define PARDON "\033[1;35m"

int main() {
	Bureaucrat mu = Bureaucrat("mu", 2);
	Bureaucrat samsak = Bureaucrat("samsak", 139);
	Bureaucrat yatong = Bureaucrat("yatong", 148);
	AForm* moon = new ShrubberyCreationForm("Moon");

	std::cout << BUREAUCRAT << mu << EOC;
	std::cout << BUREAUCRAT << samsak << EOC;
	std::cout << BUREAUCRAT << yatong << EOC;
	std::cout << SHRUBBERY << *moon << EOC;
	mu.signForm(*moon);
	std::cout << SHRUBBERY << *moon << EOC;
	mu.executeForm(*moon);
	samsak.signForm(*moon);
	std::cout << SHRUBBERY << *moon << EOC;
	samsak.executeForm(*moon);
	yatong.signForm(*moon);
	std::cout << SHRUBBERY << *moon << EOC;
	yatong.executeForm(*moon);
	delete moon;

	AForm* robot = new RobotomyRequestForm("transfomer");
	std::cout << ROBOT << *robot << EOC;
	mu.signForm(*robot);
	mu.executeForm(*robot);

	AForm* where42 = new PresidentialPardonForm("where42");
	std::cout << PARDON << *where42 << EOC;
	mu.signForm(*where42);
	mu.executeForm(*where42);
	delete where42;
}
