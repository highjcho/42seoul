#include "pipex.h"

static char	*check_cmd(char **path, char *cmd)
{
	char	*cmd_path;
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strjoin("/", cmd);
	while (path[i])
	{
		cmd_path = ft_strjoin(path[i], tmp);
		if (!access(cmd_path, F_OK) && !access(cmd_path, X_OK))
		{
			free(tmp);
			free(cmd);
			return (cmd_path);
		}
		else
			free(cmd_path);
		i++;
	}
	return (NULL);
}

static void	set_cmd(char **argv, char **envp, t_arg *args)
{
	char	**path;

	path = 0;
	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
		{
			path = ft_split(*envp + 5, ':');
			break;
		}
		envp++;
	}
	if (!path)
		error_handler("Pipex: Invalid path");
	args->cmd1_path = check_cmd(path, args->cmd1[0]);
	if (!args->cmd1_path)
		double_free(args->cmd1, args->cmd2, "Pipex: Invalid command path");
	args->cmd2_path = check_cmd(path, args->cmd2[0]);
	if(!args->cmd2_path)
	{
		free(args->cmd1_path);
		double_free(args->cmd1, args->cmd2, "Pipex: Invalid command path");
	}
	double_free(path, 0, 0);
}

void	set_arg(char **argv, char **envp, t_arg *args)
{
	args->infile = ft_strdup(argv[1]);
	if (!args->infile)
		error_handler("Pipex: Allocate failed");
	args->outfile = ft_strdup(argv[4]);
	if (!args->outfile)
		single_free(args->infile, "Pipex: Allocate failed");
	args->cmd1 = ft_split(argv[2], ' ');
	if (!args->cmd1)
	{
		free(args->infile);
		single_free(args->outfile, "Pipex: Allocate failed");
	}
	args->cmd2 = ft_split(argv[3], ' ');
	if (!args->cmd2)
	{
		free(args->infile);
		free(args->outfile);
		double_free(args->cmd1, 0, "Pipex: Allocate failed");
	}
	set_cmd(argv, envp, args);
}
