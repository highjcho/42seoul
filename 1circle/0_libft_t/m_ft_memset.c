#include <stdio.h>
#include "../libft/libft.h"
#include <string.h>

int	main(void)
{
    char    s[] = "hello world";
	printf("befroe s: %s\n", s);
	printf("after s: %s\n", memset(s, -10, 5));
	printf("after s: %s\n", ft_memset(s, -10, 5));
}
