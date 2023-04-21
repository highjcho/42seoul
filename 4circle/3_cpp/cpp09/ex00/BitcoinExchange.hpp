/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:33:07 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/04/21 15:28:53 by hyunjcho         ###   ########.fr       */
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
		std::string _date;
		double _value;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange &obj);
		~BitcoinExchange();

		void stringToMap();
		bool checkValidDate();
		bool convertDate(std::string const& date);
		bool splitAndCheckDate(std::string const& date);
		bool splitAndCheckInput(std::string const& input);

		std::string getDate() const;
		double getValue() const;
};


#endif