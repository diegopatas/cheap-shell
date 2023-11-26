#include "../incl/minishell.h"

int	cmd_echo(t_cmd *cmd)
{
	ft_putstr_fd(cmd->arg, cmd->fd);
	return (0);
}
