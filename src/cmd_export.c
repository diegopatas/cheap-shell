#include "../incl/minishell.h"

int	cmd_export(t_cmd *cmd)
{
	int i;

	i = 0;
	while (cmd->env[i++] != NULL)
		;
	ft_printf("%d\n", i);
	cmd->env[i] = "test";
	ft_printf("%s\n", cmd->env[i]);
	return (0);
}
