#include <stdio.h>
#include "../libft/libft.h"

int	main(void)
{
    char    s1[40] = "Talk is ";
    char    s2[] = "cheap";

	printf("%zu\n", ft_strlcat(s1, s2, 15));
    printf("%s", s1);
}
