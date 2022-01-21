#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"

int	main(void)
{
    char    s1[] = "come on cheap";
    //char    s2[] = "Talk is";
	printf("%s\n", memcpy(&s1[5], &s1[3], 3));
	//printf("%s\n", ft_memcpy(s1, 0, 3));
}
