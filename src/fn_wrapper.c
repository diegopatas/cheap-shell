#include "../incl/minishell.h"

static void	fd_close(int pipedes[]) {
	close(pipedes[READ_EDGE]);
	close(pipedes[WRITE_EDGE]);
	return;
}

char	*buf_load(size_t len) 
{
	char	*buf;

	if (len == 0)
		len = 255;
	buf = NULL;
	buf = (char *)malloc(sizeof(len + 1));
	buf[len] = '\0';
	return (buf);
}

char	*fn_wrapper(t_cmd *cmd, int (*fn)())
{
	char	*buf;
	size_t	len; 
	int	pid;
	int	pipedes[2];

	len = ft_strlen(cmd->arg);
	buf = buf_load(len);
	pipe(pipedes);
	pid = fork();
	if (pid == 0) {
		dup2(pipedes[WRITE_EDGE], STDOUT_FILENO);
		fd_close(pipedes);
		fn(cmd);
	}
	waitpid(pid, NULL, 0);
	read(pipedes[READ_EDGE], buf, len);
	fd_close(pipedes);
	return (buf);
}
