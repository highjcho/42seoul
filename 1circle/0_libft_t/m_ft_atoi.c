#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

int main(void)
{
    char str[] = "   -+ 1234";
    char str2[] = "   +9999999999999999992147483651231231230";
    char str3[] = "   +2147483612342342323450";
    char str4[] = "  + 1234";
    char str5[] = "  +1234";
    
    printf("o - %d\n", atoi(str));
    printf("m - %d\n", ft_atoi(str));
    printf("o - %d\n", atoi(str2));
    printf("m - %d\n", ft_atoi(str2));
    printf("o - %d\n", atoi(str3));
    printf("m - %d\n", ft_atoi(str3));
    printf("o - %d\n", atoi(str4));
    printf("m - %d\n", ft_atoi(str4));
    printf("o - %d\n", atoi(str5));
    printf("m - %d\n", ft_atoi(str5));
}
