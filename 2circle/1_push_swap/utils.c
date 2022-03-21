#include "pushswap.h"

void error_handler(char *message, int error_code)
{
	int	i;

	i = 0;
	while (message[i])
		i++;
	write(1, message, i);
	exit(error_code);
}

int	check_ascending(arr_stack *stack)
{
	
}