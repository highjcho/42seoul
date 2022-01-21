#include <stdio.h>
#include "../libft/libft.h"
#include <string.h>

int	main(void)
{
	char	str[] = "hello world";

	printf("m - %s\n", ft_strchr(str, 'w'));
	printf("o - %s\n", strchr(str, 'w'));
	printf("m - %s\n", ft_strchr(str, -1));
	printf("o - %s\n", strchr(str, -1));
	printf("m - %s\n", ft_strchr(str, 0));
	printf("o - %s\n", strchr(str, 0));
	printf("m - %s\n", ft_strchr(0, 0));
	printf("o - %s\n", strchr(0, 0));
}

