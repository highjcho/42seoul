#include <stdio.h>
#include "../libft/libft.h"

int main(void)
{
	char	str[] = "testatestatest";
	char	c = 'a';
	char	**new;
	int i = 0;

	new = ft_split(str, c);


	while (new[i])
	{
		printf("%s\n", new[i]);
		i++;
	}
}

