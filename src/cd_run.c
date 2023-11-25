#include "../incl/minishell.h"

int cd_run(t_cmd *cmd)
{
	if (chdir(cmd->arg) == -1)
		ft_printf("bash: %s: %s: No such file or directory\n", cmd->name, cmd->arg);
	pwd_run(cmd);
	return (0);
}
