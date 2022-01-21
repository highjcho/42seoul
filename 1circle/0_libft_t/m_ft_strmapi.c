#include <stdio.h>
#include "../libft/libft.h"

char	f(unsigned int n, char c)
{
	(void)n;
	if (c == 'a')
		c = ' ';
	return (c);
}

int main(void)
{
	char	(*ft)(unsigned int, char);

	ft = f;
	char	str[] = "testatestatest";
	printf("%s", ft_strmapi(str, ft));
}
