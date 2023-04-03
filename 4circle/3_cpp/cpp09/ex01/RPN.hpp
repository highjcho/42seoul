/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:33:21 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/04/03 20:10:06 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <fstream>

class RPN {
	private:
		std::stack<int> _formular;
		int _a;
		int _b;

	public:
		RPN();
		RPN(const RPN& obj);
		RPN& operator=(const RPN &obj);
		~RPN();

		void makeStack(std::string input);
		int calculator(char f);

		std::stack<int> getFormular() const;
		int getA() const;
		int getB() const;

		class ZeroDivisionException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif