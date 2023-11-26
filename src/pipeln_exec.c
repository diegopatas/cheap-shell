#include "../incl/minishell.h"
#include <stdlib.h>


static int	cmd_exec(char *cmd[])
{
	int	pid;
	char	*root;

	root = ft_strjoin("/bin/", cmd[0]);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		execve(root, cmd, NULL);
	}
	waitpid(pid, NULL, 0);
	free(root);
	return (0);
}

int	pipeln_exec(t_cmd *cmd)
{
	char **out;

	out = (char **)malloc(3 * sizeof(char *));
	out[0] = cmd->name;
	out[1] = cmd->arg;
	out[2] = NULL;
	cmd_exec(out);

	return (0);
}
