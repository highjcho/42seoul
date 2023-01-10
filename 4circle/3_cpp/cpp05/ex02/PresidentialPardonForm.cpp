/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardon.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:45:46 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/10 16:52:13 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm(P_NAME, P_SIGN, P_EXEC)
{
	std::cout << "[Create] " << PARDON << P_NAME << " Form\n\n" << EOC; 
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm(target, P_SIGN, P_EXEC)
{
	std::cout << "[Create] " << PARDON << *this << EOC; 
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
: AForm(obj)
{
	std::cout << "[Create] " << PARDON << " Copy " << P_NAME << " Form\n\n" << EOC;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj){
	return *(dynamic_cast<PresidentialPardonForm*>(&(AForm::operator=(obj))));
}

void PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const {
	checkExecute(bureaucrat);
	std::cout << "[PARDON] " << PARDON << getName() << " has been pardon by Zaphod Beeblebrox\n\n" << EOC;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[Destroy] " << PARDON <<  P_NAME << " " << getName() << " Form\n" << EOC;
}