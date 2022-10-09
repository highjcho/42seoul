/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:02:13 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/09 14:57:35 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void replaceStr(std::ofstream &outfile, std::string &str, std::string to_find, std::string replace) {
	std::string search;
	std::string new_str;
	size_t r_size = replace.size();
	size_t idx = 0;
	size_t n;

	while (str[idx]) {
		search = str.substr(idx);
		n = search.find(to_find);
		if (n != std::string::npos) {
			new_str = search.substr(0, n);
			outfile << new_str << replace;
			idx += r_size + n;
		}
		else {
			outfile << search;
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