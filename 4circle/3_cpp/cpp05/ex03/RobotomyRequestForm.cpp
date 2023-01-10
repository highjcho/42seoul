/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:02:49 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/10 16:51:59 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm(R_NAME, R_SIGN, R_EXEC)
{
	std::cout << "[Create] " << ROBOT << R_NAME << " Form\n\n" << EOC; 
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm(target, R_SIGN, R_EXEC)
{
	std::cout << "[Create] " << ROBOT << *this << EOC; 
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
: AForm(obj)
{
	std::cout << "[Create] " << ROBOT << " Copy " << R_NAME << " Form\n\n" << EOC;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj){
	return *(dynamic_cast<RobotomyRequestForm*>(&(AForm::operator=(obj))));
}

void RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const {
	checkExecute(bureaucrat);
	time_t now = time(NULL);
	struct tm* t = localtime(&now);
	std::cout << "[Robot] " << ROBOT << "drrrr.. => ";
	if (t->tm_sec % 2 == 0)
		std::cout << getName() << " has been robotomized successfully\n\n" << EOC;
	else
		std::cout << getName() << " has been failed robotomized\n\n" << EOC;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[Destroy] " << ROBOT <<  R_NAME << " " << getName() << " Form\n" << EOC;
}