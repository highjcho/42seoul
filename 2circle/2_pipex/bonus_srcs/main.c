#include "pipex.h"

static void	set_arg(int argc, char **argv, t_arg *args)
{
	if (args->here_doc == TRUE)
	{
		args->limiter = ft_strdup(argv[1]);
		if (!args->limiter)
			error_handler("Pipex: Allocate failed.");
		args->infile = NULL;
	}
	else
	{
		args->infile = ft_strdup(argv[1]);
		if (!args->infile)
			error_handler("Pipex: Allocate failed.");
		args->limiter = NULL;
	}
	args->outfile = ft_strdup(argv[argc - 1]);
	if (!args->outfile)
	{
		if (!args->infile)
			single_free(args->limiter, "Pipex: Allocate failed.");
		else
			single_free(args->infile, "Pipex: Allocate failed.");
	}
	args->cnt = argc - 3;
}

static void	set_here_doc(int *argc, char** argv, t_arg *args)
{
	int	i;

	i = 1;
	while (++i < argc + 1)
		argv[i - 1] = argv[i];
	args->here_doc = TRUE;
	*argc--;
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	args;

	if (argc < 5)
		error_handler("Pipex: Invalid argument");
	if (!ft_strncmp(argv[1], "here_doc", 8))
		set_here_doc(&argc, argv, &args);
	else
		args.here_doc = FALSE;
	multi_pipex(&args, envp);
	return (0);
}