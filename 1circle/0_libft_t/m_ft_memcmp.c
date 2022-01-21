#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"

int main(void)
{
    char    s1[] = "ababcfg";
    char    s2[] = "bb";
    printf("%d\n", ft_memcmp(s1, s2, 3));
    printf("%d\n", memcmp(s1, s2, 3));
    printf("%d\n", ft_memcmp(0, 0, 0));
	printf("%d\n", memcmp(0, 0, 0));
   	printf("%d\n", ft_memcmp(s1, (char *)s1 + 2, 3));
	printf("%d\n", memcmp(s1, (char *)s1 + 2, 3));
    printf("%d\n", ft_memcmp(s1, (char *)s1 + 2, 0));
	printf("%d\n", memcmp(s1, (char *)s1 + 2, 0));
    printf("%d\n", ft_memcmp(0, (char *)s1 + 2, 4));
	printf("%d\n", memcmp(0, (char *)s1 + 2, 4));
	printf("%d\n", ft_memcmp(0, s2, 3));
	printf("%d\n", memcmp(0, s2, 3));
}
