#include <stdio.h>
#include "../libft/libft.h"
#include <string.h>

int	main(void)
{
    char    s1[] = "come on cheap";
    char    s2[] = "Talk is";
	char	s3[] = "come on cheap";
	char	s4[] = "Talk is";

	printf("%zu\n", ft_strlcpy(s1, s2, 0));
    printf("%zu\n", strlcpy(s3, s4, 0));
	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%s\n", s3);
	printf("%s\n", s4);
}
