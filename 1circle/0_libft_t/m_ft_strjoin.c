#include <stdio.h>
#include "../libft/libft.h"

int main(void)
{
    char str[] = "hello";
    char str2[] = " world";
    printf("%s\n", ft_strjoin(str, str2));
}