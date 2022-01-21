#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"

int	main(void)
{
    char    s[] = "hello world";
	printf("befroe s: %s\n", s);
	ft_bzero(s, 5);
	for (int i = 0; i < 11; i++)
	{
		write(1, &s[i], 1);
	}
}