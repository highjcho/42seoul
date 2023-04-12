/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:33:07 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/04/12 14:22:51 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

class BitcoinExchange {
	private:
		int _year;
		int _month;
		int _day;
		std::string _sDate;
		int _iDate;
		double _value;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange &obj);
		~BitcoinExchange();

		void stringToMap();
		bool splitAndCheckInput(std::string input);
		bool convertDate(std::string &date);
		bool checkValidDate();
		bool splitAndCheckDate(std::string date);

		std::string getSDate() const;
		int getIDate() const;
		double getValue() const;
		int getYear() const;
		int getMonth() const;
		int getDay() const;
};


#endif