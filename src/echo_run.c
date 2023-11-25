#include "../incl/minishell.h"

int echo_run(t_cmd *cmd)
{
	ft_putstr_fd(cmd->arg, cmd->fd);
	return (0);
}
