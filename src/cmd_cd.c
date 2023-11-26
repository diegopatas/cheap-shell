#include "../incl/minishell.h"

int cmd_cd(t_cmd *cmd)
{
	if (chdir(cmd->arg) == -1)
		ft_printf("bash: %s: %s: No such file or directory\n", cmd->name, cmd->arg);
	cmd_pwd(cmd);

	return 0;
}
