#include <iostream>
#include <cctype>

int main(int ac, char **av) {
	int	i;
	int	j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for(i = 1; i < ac; i++) {
			for(j = 0; av[i][j]; j++) {
				std::cout << static_cast<char>(toupper(av[i][j]));
			}
		}
		std::cout << "\n";
	}
}