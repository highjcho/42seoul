/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:13:25 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/10 20:05:28 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& obj);
		Intern& operator=(const Intern &obj);
		~Intern();

		AForm* makeForm(const std::string& form, const std::string& target);

		class NoFormException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif