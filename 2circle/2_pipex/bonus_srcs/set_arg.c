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
			return (cmd_path);
		}
		else
			free(cmd_path);
		i++;
	}
	return (NULL);
}

static void	set_path(char **argv, char **envp, t_arg *args)
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
		error_handler("Pipex: Allocate failed."); // 이 시점에 args가 뭐뭐 할당 돼있는 지 확인하고 free처리 해줘야 할듯
	args->path = check_cmd(path, args->cmd[0]);
	if (!args->path)
		double_free(args->cmd, 0, "Pipex: Invalid command path");
	double_free(path, 0, 0);
}

void	set_cmd(char **argv, char **envp, t_arg *args, int i)
{
	char	**path;
	
	args->cmd = ft_split(argv[i + 2], ' '); // 반복문 횟수와 일치한다고 가정할 때 명령어의 위치와
	if (!args->cmd)
	{
		free(args->first);
		single_free(args->outfile, "Pipex: Allocate failed");
	}
	set_path(argv, envp, args);
}
