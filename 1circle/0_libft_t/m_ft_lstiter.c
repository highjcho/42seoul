#include <stdio.h>
#include "../libft/libft.h"

void	f(void	*content)
{
	int	i;
	char *p;

	p = (char *)content;
	i = 0;
	while (p[i])
	{
		if (p[i] == ' ')
			p[i] = '+';
		i++;
	}
}

int main(void)
{
	char 	s1[] = "test a";
	char 	s2[] = "test b";
	char 	s3[] = "test c";
	t_list 	*t1 = ft_lstnew(s1);
	t_list	*t2 = ft_lstnew(s2);
	t_list 	*t3 = ft_lstnew(s3);

	t1->next = t2;
	t2->next = t3;

	printf("%s\n", t1->content);
	printf("%s\n", t2->content);
	printf("%s\n", t3->content);


	ft_lstiter(t1, f);
	printf("\n\n");

	printf("%s\n", t1->content);
	printf("%s\n", t2->content);
	printf("%s\n", t3->content);
}
