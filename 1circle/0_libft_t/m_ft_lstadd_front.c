#include <stdio.h>
#include "../libft/libft.h"

int	main(void)
{
	//char	str1[] = "hello";
    char    str2[] = "world";
	//t_list	lst;
    //t_list  *new;
    t_list  *origin;

	//new = ft_lstnew(str1);
    origin = ft_lstnew(str2);
    //lst = origin;

	printf("%p\n", origin);
	printf("%p\n", origin->content);





/*	printf("origin content : %s\n", origin->content);
    printf("origin address : %p\n", &origin);
    printf("origin p address : %p\n", origin);
	printf("origin next : %p\n", origin->next);
    printf("new content : %s\n", new->content);
    printf("new address : %p\n", &new);
    printf("new p address : %p\n", new);
	printf("new next : %p\n", new->next);
    printf("lst content : %s\n", lst->content);
    printf("lst address : %p\n", &lst);
    printf("lst p address : %p\n", lst);
	printf("lst next : %p\n", lst->next);

    ft_lstadd_front(&lst, new);

    printf("\n\n");
	printf("origin content : %s\n", origin->content);
    printf("origin address : %p\n", &origin);
    printf("origin p address : %p\n", origin);
	printf("origin next : %p\n", origin->next);
    printf("new content : %s\n", new->content);
    printf("new address : %p\n", &new);
    printf("new p address : %p\n", new);
	printf("new next : %p\n", new->next);
    printf("lst content : %s\n", lst->content);
    printf("lst address : %p\n", &lst);
    printf("lst p address : %p\n", lst);
	printf("lst next : %p\n", lst->next);


    printf("\n\n");
    if (new->next == origin && origin->next == 0)
        printf("Linking Success!");
    else 
        printf("Linking Fail");*/
}
