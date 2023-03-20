/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:47:08 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/03/20 18:04:01 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <cstdlib>
#include <fstream>

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
		bool splitAndCheckDate(std::string date);
		bool checkValidDate();

		std::string getSDate() const;
		int getIDate() const;
		double getValue() const;
		int getYear() const;
		int getMonth() const;
		int getDay() const;
};


#endif