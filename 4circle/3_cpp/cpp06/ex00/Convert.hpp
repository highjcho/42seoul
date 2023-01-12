/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:04:44 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/12 22:49:56 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

#include <iostream>
#include <iostream>
#include <cmath> // isnan, ininf, floor
#include <cstdlib> // strtod
#include <climits> // CHAR_MIN, CHAR_MAX
#include <cfloat> // FLT_MAX
#include <locale> // isprint
#include <iomanip> // setprecision

class Convert {
	private:
		std::string _input;
		double _value;
		bool _flag;
		Convert();

	public:
		Convert(std::string input);
		Convert(const Convert& obj);
		Convert& operator=(const Convert &obj);
		~Convert();

		char toChar();
		int toInt();
		float toFloat();
		double toDouble();

		void print();
		void printChar();
		void printInt();
		void printFloat();
		void printDouble();

		std::string getInput() const;
		double getValue() const;
		bool getFlag() const;
		bool getNan() const;
		bool getInf() const;

		class ImpossibleException : public std::exception {
			public:
				const char* what() const throw();
		};
		class NonDisplayableException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif