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
		if (!access(cmd_path, F_OK) || !access(cmd_path, X_OK))
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
			path = ft_split(*envp + 5, ':'); // path가 차면 break;해주고싶은데 줄수가 모자라서 걍 지움. 고칠 수 있음 고치기
		envp++;
	}
	if (!path)
		error_handler("Pipex: Invalid path");
	args->cmd1_path = check_cmd(path, args->cmd1[0]); 
	if (!args->cmd1_path)
	{
		cmd_free(args->cmd1, args->cmd2);
		error_handler("Pipex: Invalid command path");
	}
	args->cmd2_path = check_cmd(path, args->cmd2[0]);
	if(!args->cmd2_path)
	{
		cmd_free(args->cmd1, args->cmd2);
		free(args->cmd1_path);
		error_handler("Pipex: Invalid command path");
	}
	printf("args->cmd1_path: %s\n", args->cmd1_path);
	printf("args->cmd2_path: %s\n", args->cmd2_path);
	cmd_free(path, 0);
}

static int	redirect_in(char *infile)
{
	int	in_fd;
	int	dup_ret;
	
	in_fd = open(infile, O_RDONLY);
	if (in_fd < 0)
		return (in_fd);
	dup_ret = dup2(in_fd, 0);
	if (dup_ret < 0)
		return (dup_ret);
	return (in_fd);
}

static int	redirect_out(char *outfile)
{
	int	out_fd;
	int	dup_ret;

	out_fd = open(outfile, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (out_fd < 0)
		return (out_fd);
	dup_ret = dup2(out_fd, 1);
	if (dup_ret < 0)
		return (dup_ret);
	return (out_fd);
}

void	set_arg(char **argv, char **envp, t_arg *args)
{
	args->in_fd = redirect_in(argv[1]);
	if (args->in_fd < 0)
		error_handler("Pipex: Infile open failed");
	args->out_fd = redirect_out(argv[4]);
	if (args->out_fd < 0)
		error_handler("Pipex: Outfile open failed");
	args->cmd1 = ft_split(argv[2], ' ');
	if (!args->cmd1)
		error_handler("Pipex: Allocate failed");
	args->cmd2 = ft_split(argv[3], ' ');
	if (!args->cmd2)
	{
		cmd_free(args->cmd1, 0);
		error_handler("Pipex: Allocate failed");
	}
	set_cmd(argv, envp, args);
}
