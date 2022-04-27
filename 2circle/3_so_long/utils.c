#include "so_long.h"

void	error_handler(char *msg, int err)
{
	perror(msg);
	exit(err);
}