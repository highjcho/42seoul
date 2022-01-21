#include <stdio.h>
#include "../libft/libft.h"
#include <string.h>

int	main(void)
{
    char str[] = "take is cheap, all talk no action";
    char str2[] = "cheap";
    printf("%s\n", ft_strnstr(str, str2, 12));
    printf("%s\n", strnstr(str, str2, 12));
    printf("%s\n", ft_strnstr(str, str2, 20));
    printf("%s\n", strnstr(str, str2, 20));
}