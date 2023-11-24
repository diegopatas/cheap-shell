#include "../incl/minishell.h"

static void	fd_close(int pipedes[]) {
	close(pipedes[READ_EDGE]);
	close(pipedes[WRITE_EDGE]);
	return;
}
// static	void	run(char *str, size_t len) {
// 	// write(STDOUT_FILENO, &str[0], len);
// 	ft_putstr_fd(str, STDOUT_FILENO);
// 	return;
// }
char	*buf_load(t_cmd *cmd, size_t len) 
{
	char	*buf;

	buf = NULL;
	buf = (char *)malloc(sizeof(len + 1));
	ft_strlcpy(buf, cmd->arg, len);
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
	buf = buf_load(cmd, len);
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
