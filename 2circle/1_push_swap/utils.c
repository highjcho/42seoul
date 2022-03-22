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

int	check_ascending(arr_stack *a) // 맞는지 확인 필요
{
	int max;
	int	i;

	max = a->element[0].data;
	i = 0;
	while (i++ < a->max_count)
	{
		if (a[i] < max)
			return (0);
	}
	return (0);
}