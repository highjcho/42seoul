/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:40:48 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/03/20 19:34:36 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iomanip>

int stringToInt(std::string date) {
	if (date.length() < 10)
		return (0);
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	std::string tmp;
	tmp.append(year);
	tmp.append(month);
	tmp.append(day);
	return(atoi(tmp.c_str()));
}

void fileToMap(std::map<int, double> &db) {
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
				if (date < iter->first) {
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
	fileToMap(db);
	int i = 0;
	while (getline(inputFile, line)) { // line으로 돌릴 수 있는 방법?
		if (i == 0 && line == "date | value")
			getline(inputFile, line);
		if (!bitcoinExchanger.splitAndCheckInput(line))
			continue;
		iter = findPrice(db, bitcoinExchanger.getIDate());
		if (iter != db.end()) {
			std::cout << bitcoinExchanger.getSDate() << " => " << bitcoinExchanger.getValue() << " = " << \
				iter->second * bitcoinExchanger.getValue() << std::endl; // 출력 문제
		}
		i++;
	}
}