#include <stdio.h>
#include "../libft/libft.h"

int	main(void)
{
	char	str[] = "hello";
	t_list	*l1;

	l1 = ft_lstnew(str);
	printf("content : %s\n", l1->content);
	printf("next : %p", l1->next);
}