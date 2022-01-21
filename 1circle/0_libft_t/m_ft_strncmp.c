#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"

int main(void)
{
    char    s1[] = "ababcfg";
    char    s2[] = "bb";
    printf("%d\n", ft_strncmp(s1, s2, 3));
    printf("%d\n", strncmp(s1, s2, 3));
   	printf("%d\n", ft_strncmp(s1, (char *)s1 + 2, 2));
	printf("%d\n", strncmp(s1, (char *)s1 + 2, 2));
}
