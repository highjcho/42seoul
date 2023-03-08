/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:02:49 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/13 13:04:38 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm(R_NAME, R_SIGN, R_EXEC) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm(target, R_SIGN, R_EXEC) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
: AForm(obj) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj){
	return *(dynamic_cast<RobotomyRequestForm*>(&(AForm::operator=(obj))));
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const {
	checkExecute(bureaucrat);
	srand(time(NULL));
	std::cout << "[Robot] drrrr.. => ";
	if (rand() % 2 == 0)
		std::cout << getName() << " has been robotomized successfully\n\n";
	else
		std::cout << getName() << " has been failed robotomized\n\n";
}

AForm* RobotomyRequestForm::makeRobot(const std::string& target) {
	return new RobotomyRequestForm(target);
}