/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:31:34 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/13 12:44:03 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

# define ERR "\033[1;31m"
# define EOC "\033[0;0m"
# define HIGH 1
# define LOW 150

class AForm;

class Bureaucrat {
	private :
		const std::string _name;
		int _grade;

	public :
		Bureaucrat();
		Bureaucrat(const std::string& name, int const grade);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat& operator=(Bureaucrat const &other);
		~Bureaucrat();

		void signForm(const AForm& form) const;
		void executeForm(const AForm& form) const;
		
		const std::string& getName() const;
		int getGrade() const;
		void increment();
		void decrement();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& obj);
	
#endif
