#include <stdio.h>
#include "../libft/libft.h"

void    f(unsigned int  i, char *s)
{
    (void)i;
    if (*s == 'a')
        *s = ' ';
}

int main(void)
{
    char str[] = "testatestatest";

    printf("%s\n", str);
    ft_striteri(str, f);
    printf("%s\n", str);
}