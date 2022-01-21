#include "../libft/libft.h"
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	str[] = "hello world";

	printf("m - %s\n", ft_memchr(str, 'w', 10));
	printf("o - %s\n", memchr(str, 'w', 10));
	printf("m - %s\n", ft_memchr(str, 0, 3));
	printf("o - %s\n", memchr(str, 0, 3));
    printf("m - %s\n", ft_memchr(str, 0, 11));
	printf("o - %s\n", memchr(str, 0, 11));
	printf("m - %s\n", ft_memchr(0, 'w', 5));
	printf("o - %s\n", memchr(0, 'w', 5));
	printf("m - %s\n", ft_memchr(0, 0, 4));
	printf("o - %s\n", memchr(0, 0, 4));
}
