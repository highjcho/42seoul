/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:02:56 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/13 12:50:26 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm(S_NAME, S_SIGN, S_EXEC) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm(target, S_SIGN, S_EXEC) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
: AForm(obj) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj){
	return *(dynamic_cast<ShrubberyCreationForm*>(&(AForm::operator=(obj))));
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const {
	checkExecute(bureaucrat);
	std::ofstream out(getName() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
	if (!out.good())
		throw FileErrorException();
	std::string shrubbery =	
		"													 |\n\
													-x-\n\
													 |\n\
					v .   ._, |_  .,\n\
				`-._\\/  .  \\ /    |/_\n\
					\\  _\\, y | \\//\n\
				_\\_.___\\, \\/ -.\\||\n\
				`7-,--.`._||  / / ,\n\
				/'     `-. `./ / |/_.'\n\
							|    |//\n\
							|_    /\n\
							|-   |\n\
							|   =|\n\
							|    |\n\
		--------------------/ ,  . \\--------._";
	out << shrubbery;
	out.close();
	std::cout << "[Shrubbery] tree making success\n\n";
}