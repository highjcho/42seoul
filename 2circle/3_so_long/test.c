#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(int ac, char **av)
{
	char s[100];
	char **map;
	char *line;
	int fd;
	int rv;
	int	i;
	int j;

	fd = open(av[1], O_RDONLY);
	rv = read(fd, s, 99);
	while (rv)
	{
		printf("%s", s);
		rv = read(fd, s, 99);
	}
}