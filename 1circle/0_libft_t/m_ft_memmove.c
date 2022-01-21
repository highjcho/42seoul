#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"

int	main(void)
{
    char    s1[] = "come on cheap";
	char	s2[] = "come on cheap";
	printf("%s\n", memmove(&s1[5], &s1[3], 4));
	printf("%s\n", ft_memmove(&s2[5], &s2[3], 4));
}
