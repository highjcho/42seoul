
void	pipddddex(t_arg *args, int *fd, char **envp, pid_t *pid)
{
	if (*pid == 0)
	{
		redirect_in(args);
		direct_pipe(args, fd, 1, 0);
		if (execve(args->cmd1_path, args->cmd1, envp) > 0)
			all_free(args, "Pipex: Execute failed.");
	}
	else
	{
		wait(pid);
		direct_pipe(args, fd, 0, 1);
		redirect_out(args);
		if (execve(args->cmd2_path, args->cmd2, envp) > 0)
			all_free(args, "Pipex: Execute failed.");
	}
}

int pipeA[2];
int pipeB[2];
int i;
pid_t pid;

i = -1;
while (++i < num_pipe + 1)
{
	if (!(i % 2))
		if (pipe(pipeA) < 0)
			exit(1);
	if (i % 2)
		if (pipe(pipeB) < 0)
			exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	else if (!pid)
		child_proc();
	else
		parent_proc();
}

/*
** child_proc
** (각 과정에 대한 처리에서 필요 없는 파일 디스크립터를 적절히 닫는 과정이 필요하다.)
**
** 최초: 파일에서 읽는 작업을 수행
**
** 최종: 파일에 쓰는 작업을 수행
**
** 중간: 짝수 index인지, 홀수 index인지에 따라 어느 파이프의 Read, Write를 Redirection할 지 달라진다.
**      홀수 index -> A 파이프에서 읽어야 하므로 A 파이프의 Read를 STDIN으로 dup2를 수행한다.
**                   B 파이프에 써야 하므로, B 파이프의 Write를 STDOUT으로 dup2를 수행한다.
**      짝수 index -> B 파이프에서 읽어야 하므로 B 파이프의 Read를 STDIN으로 dup2를 수행한다.
**                   A 파이프에 써야 하므로, A 파이프의 Write를 STDOUT으로 dup2를 수행한다.
*/

/*
** parent_proc의 명령어 index에 따른 처리
** (현 index의 처리는 fork 시점 이후 임을 명심한다.)
** 
** 최초: 짝수 index이고 읽을 내용은 파일에 있으므로, A 파이프의 Write만 닫는다.
**
** 최종: 짝수 index인지, 홀수 index인지에 따라 어느 파이프의 Write를 닫는지 달라진다.
**      홀수 index -> 기존에는 B 파이프에 Write를 하겠지만, 파일에 Write를 수행할 것이므로 B 파이프의 Write는 필요가 없다.
**      짝수 index -> 기존에는 A 파이프에 Write를 하겠지만, 파일에 Write를 수행할 것이므로 A 파이프의 Write는 필요가 없다.
**
** 중간: 짝수 index인지, 홀수 index인지에 따라 어느 파이프의 Read, Write를 닫는지 달라진다.
**      홀수 index -> 다음 반복문은 짝수 index이므로 B 파이프에서 읽고, A 파이프에 쓸 것이다.
**                   따라서 B 파이프의 Write를 닫고, A 파이프의 Read를 닫는다.
**      짝수 index -> 다음 반복문은 홀수 index이므로 A 파이프에서 읽고, B 파이프에 쓸 것이다.
**                   따라서 A 파이프의 Write를 닫고, B 파이프의 Read를 닫는다.
**
** 명령어 index에 따른 처리가 끝났다면, 자식 프로세스의 현 명령어 수행을 기다리도록 적절히 wait / waitpid를 이용한다.
** 만일 자식 프로세스에서 Exception이 발생했다면, 적절히 status를 분석한다. // 이건 또 어쩌라는거냐 ㅎㅎㅎㅎ status를 어케 분석혀 ;
** exec 함수는 자식 프로세스 자체를 교체하여 수행된다는 점을 유의해야 한다. // 이게 먼말이냐 ㅎㅎㅎㅎㅎㅎ
->내가 할 수 있는 것이 아닌가..... 좀 다른 방법을 찾아봐야겠다
*/

// You will get extra points if you:
// • Handle multiple pipes.
// $> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
// Should behave like:
// < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

// • Support « and » when the first parameter is "here_doc".
// $> ./pipex here_doc LIMITER cmd cmd1 file
// Should behave like:
// cmd << LIMITER | cmd1 >> file
//pipe heredoc> 

//그럼 하고 난 구조체 프리는 어디서 해야하지???