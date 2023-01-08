/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:31:34 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/06 22:11:53 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

# define MAX 1
# define MIN 150

class Bureaucrat {
	private :
		const std::string _name;
		int _grade;
		Bureaucrat();

	public :
		Bureaucrat(const std::string& name, int const grade);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat& operator=(Bureaucrat const &other);
		~Bureaucrat();

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
