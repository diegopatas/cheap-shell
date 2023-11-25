#include "../incl/minishell.h"

int pwd_run(t_cmd *cmd)
{
	char *pwd = getcwd(NULL, 256);
	ft_putstr_fd(pwd, cmd->fd);
	free(pwd);
	return (0);
}
