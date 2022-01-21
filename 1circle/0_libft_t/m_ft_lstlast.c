#include <stdio.h>
#include "../libft/libft.h"

int	main(void)
{
	char	s1[] = "1";
	char	s2[] = "2";
	char	s3[] = "3";
	char	s4[] = "4";
	char	s5[] = "the last one";
	t_list *t1;
	t_list *t2;
	t_list *t3;
	t_list *t4;
	t_list *t5;

	t1 = ft_lstnew(s1);
	t2 = ft_lstnew(s2);
	t3 = ft_lstnew(s3);
	t4 = ft_lstnew(s4);
	t5 = ft_lstnew(s5);
	t1->next = t2;
	t2->next = t3;
	t3->next = t4;
	t4->next = t5;

	printf("%s", ft_lstlast(t1)->content);
}