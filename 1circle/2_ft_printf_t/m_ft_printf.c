#include <stdio.h>
#include "../2_ft_printf/srcs/ft_printf.h"
#include "../2_ft_printf/bonus_srcs/ft_printf_bonus.h"

int main(void)
{
	//ft_printf("%%pep");
	int a;
	a = 124;
	printf("%--99999999999999999999999999999d", a);
}
