#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"

int main(void)
{
	char	str[] = "hello world";

	printf("o - %s\n", strdup(str));
	printf("m - %s\n", ft_strdup(str));
	printf("o - %s\n", strdup(0));
	printf("m - %s\n", ft_strdup(0));
}
