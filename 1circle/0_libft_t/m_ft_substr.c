#include <stdio.h>
#include "../libft/libft.h"
#include <string.h>

int main(void)
{
    char str[] = "hello world";
    printf("%s\n", ft_substr(str, 6, 5));
    printf("m - %s\n", ft_substr(str, 30, 6));
	printf("o - %s\n", substr(str, 30, 6));
    printf("%s\n", ft_substr(str, 6, 0));
    printf("%s\n", ft_substr(str, 6, 8));
}
