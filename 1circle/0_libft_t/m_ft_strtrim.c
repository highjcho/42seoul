#include <stdio.h>
#include "../libft/libft.h"

int main(void)
{
    char *s1 = " \t \t \n    \n\n\n\t";
    char *str2 = "";
    char *set = ft_strtrim(s1, " \n\t");
	printf("1-%s\n", ft_strdup(""));
  	printf("%s\n", ft_strtrim(str2, set));
	printf("2-%s\n", str2);
    printf("3-%s\n", set);
}
