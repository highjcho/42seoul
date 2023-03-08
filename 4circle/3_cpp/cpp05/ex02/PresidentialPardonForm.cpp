/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:45:46 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/13 12:49:09 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm(P_NAME, P_SIGN, P_EXEC) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm(target, P_SIGN, P_EXEC) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
: AForm(obj) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj){
	return *(dynamic_cast<PresidentialPardonForm*>(&(AForm::operator=(obj))));
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const {
	checkExecute(bureaucrat);
	std::cout << "[PARDON] " << getName() << " has been pardon by Zaphod Beeblebrox\n\n";
}