/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:02:13 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/20 17:31:52 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void replaceStr(std::ofstream &outfile, std::string &str, std::string to_find, std::string replace) {
	std::string new_str;
	size_t size = to_find.size();
	size_t idx = 0;
	size_t n;

	while (str[idx]) {
		n = str.find(to_find, idx);
		if (n != std::string::npos) {
			new_str = str.substr(idx, n - idx);
			outfile << new_str << replace;
			idx = size + n;
		}
		else {
			outfile << str.substr(idx);
			break;
		}
	}
}

int main(int ac, char** av) {
	std::string in_file(av[1]);
	std::ifstream infile(in_file);
	std::ofstream outfile(in_file + ".replace");
	std::string str;

	if (ac != 4) {
		std::cout << "Input error. (Usage: ./sed infile, to_find, replace)\n";
		exit(EXIT_FAILURE);
	}
 	if (infile.is_open() && outfile.is_open()) {
		while(std::getline(infile, str)) {
			replaceStr(outfile, str, av[2], av[3]);
			if (!infile.eof())
				outfile << "\n";
		}
	}
	else {
		std::cout << "File open error\n";
		exit(EXIT_FAILURE);
	}
	infile.close();
	outfile.close();
	exit(EXIT_SUCCESS);
}