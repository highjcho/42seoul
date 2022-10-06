#include <iostream>
#include <fstream>

std::string replace_str(std::string str, std::string original, std::string replace) {
	std::string new_str;
	size_t n = str.find(original);

	if (n != std::string::npos) {
		new_str = str.substr(0, n);
		new_str += replace;
		new_str += str.substr(n + original.size());
		return new_str;
	}
	return str;
}

int main(int ac, char** av) {
	char* tmp = strdup(av[1]);
	char* in_name = strdup(tmp);
	char* out_name = strcat(tmp, ".replace");
	std::ifstream infile(in_name);
	std::ofstream outfile(out_name);
	std::string str;

	if (ac != 4) {
		std::cout << "We need more information!\n";
		return (0);
	}
 	if (infile.is_open() && outfile.is_open()) {
		while(!infile.eof()) {
			std::getline(infile, str);
			str = replace_str(str, av[2], av[3]);
			outfile << str << "\n";
		}
	}
	else
		std::cout << "File open error\n";
}