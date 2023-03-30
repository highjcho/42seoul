/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:00:29 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/03/30 18:50:38 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <map>

int stringToInt(std::string date) {
	if (date.length() < 10)
		return (0);
	std::stringstream ss;

	ss << date.substr(0, 4) << date.substr(5, 2) << date.substr(8, 2);
	int ret;
	ss >> ret;
	std::cout << ret << std::endl;
	return(ret);
}

void makeDBMap(std::map<int, double> &db) {
	std::ifstream data("data.csv");
	std::string line;
	int i;

	if (data.fail()) {
		std::cerr << "Error: can't open database\n";
		exit(EXIT_FAILURE);
	}
	getline(data,line);
	while (getline(data, line)) {
		int len = line.length();
		for (i = 0; i < len; i++) {
			if (line[i] == ',')
				break;
		}
		int date = stringToInt(line.substr(0, i));
		db.insert(std::make_pair(date, atof((line.substr(i + 1, len - i - 1)).c_str())));
	}
	data.close();
}

std::map<int,double>::iterator findPrice(std::map<int, double> &db, int date) {
	std::map<int, double>::iterator iter;

	iter = db.find(date);
	if (iter == db.end()) {
		if (db.begin()->first > date) {
			std::cerr << "Error: cannot find the lower date\n";
			return db.end();
		}
		iter--;
		if (iter->first > date) {
			for (iter = db.begin(); iter != db.end(); iter++) {
				if (iter->first > date) {
						iter--;
					break;
				}
			}
		}
	}
	return iter;
}

int	main(int ac, char **av) {
	BitcoinExchange bitcoinExchanger;
	std::map<int, double> db;
	std::map<int, double>::iterator iter;
	std::string line;

	if (ac != 2) {
		std::cerr << "Error: could not open file.\n";
		exit(EXIT_FAILURE);
	}
	std::ifstream inputFile(av[1]);
	if (inputFile.fail()) {
		std::cerr << "Error: could not open file.\n";
		exit(EXIT_FAILURE);
	}
	makeDBMap(db);
	int i = 0;
	while (getline(inputFile, line)) {
		if (i == 0 && line == "date | value")
			getline(inputFile, line);
		if (!bitcoinExchanger.splitAndCheckInput(line))
			continue;
		iter = findPrice(db, bitcoinExchanger.getIDate());
		if (iter != db.end()) {
			std::cout << bitcoinExchanger.getSDate() << " => " << bitcoinExchanger.getValue() << " = " << \
				iter->second * bitcoinExchanger.getValue() << std::endl;
		}
		i++;
	}
}