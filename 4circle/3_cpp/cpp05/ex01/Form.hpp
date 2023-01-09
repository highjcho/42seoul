/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:24:00 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/09 20:12:27 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		bool _flag;
		const int _sign;
		const int _execute;

	public:
		Form();
		Form(const std::string name, const int sign, const int execute);
		Form(const Form& obj);
		Form& operator=(const Form &obj);
		~Form();

		void beSigned(const Bureaucrat& bureaucrat);
		
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

};

std::ostream& operator<<(std::ostream& o, const Form& obj);

#endif