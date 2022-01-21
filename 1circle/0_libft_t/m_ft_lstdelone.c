#include <stdio.h>
#include "../libft/libft.h"

void d(void *str)
{
	free(str);
}

int main(void)
{
	char	str1[] = "s1";
	//char	str2[] = "s2";
	char	str3[] = "s3";

	char *str;
	str = (char *)malloc(sizeof(char) * 3);
	str[0] = 's';
	str[1] = '4';
	str[2] = '\0';
	t_list	*t1 = ft_lstnew(str1);
	t_list 	*t2 = ft_lstnew(str);
	t_list	*t3 = ft_lstnew(str3);

	t1->next = t2;
	t2->next = t3;

	printf("%p\n", t1->content);
	printf("%p\n", t2->content);
	printf("%p\n", t3->content);

	ft_lstdelone(t2, d);

	printf("%s", t1->content);
	printf("%s", t2->content);
	printf("%s", t3->content);
}
