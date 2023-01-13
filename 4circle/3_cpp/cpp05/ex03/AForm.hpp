/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:18:20 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/13 13:00:30 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

#include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string _name;
		bool _flag;
		const int _sign;
		const int _execute;

	public:
		AForm();
		AForm(const std::string name, const int sign, const int execute);
		AForm(const AForm& obj);
		AForm& operator=(const AForm &obj);
		virtual ~AForm();

		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(const Bureaucrat& bureaucrat) const = 0;
		void checkExecute(const Bureaucrat& Bureaucrat) const;

		const std::string& getName() const;
		bool getFlag() const;
		const int& getSign() const;
		const int& getExecute() const;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class RequiredSignException : public std::exception {
			public:
				const char* what() const throw();
		};
		class FileErrorException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& o, const AForm& obj);

#endif