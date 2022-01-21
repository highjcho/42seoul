#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"

int	main(void)
{
	char	s[] = "hello world";

	printf("m - %s\n", ft_strrchr(s, 'h'));
	printf("o - %s\n", strrchr(s, 'h'));
	printf("m - %s\n", ft_strrchr(s, 0));
	printf("o - %s\n", strrchr(s, 0));
	printf("m - %s\n", ft_strrchr(0, 'o'));
	printf("o - %s\n", strrchr(0, 'o'));
	printf("m - %s\n", ft_strrchr(s, 0));
	printf("o - %s\n", strrchr(s, 0));
}
