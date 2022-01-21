#include <stdio.h>
#include "../libft/libft.h"
//#include <fcntl.h>
int main(void)
{
//	int fd = open("1.txt", O_WRONLY);
	ft_putchar_fd('c', 2);
//	printf("%d", fd);
	printf("\n");
	ft_putstr_fd("hello world", 1);
	printf("\n");
	ft_putnbr_fd(999, 1);
}

