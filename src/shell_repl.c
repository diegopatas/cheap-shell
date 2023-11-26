#include "../incl/minishell.h"
#include <stdlib.h>

int	shell_repl(t_sh *shell)
{
	char	**aux;
	t_cmd	*cmd;

	cmd = NULL;
	aux = ft_split(shell->input, ' ');
	cmd = ds_create();
	cmd->name = aux[0];
	cmd->arg = aux[1];
	if (builtin_check(cmd->name))
		builtin_exec(cmd);
	else 
		cmd_run(cmd);
	cmd = ds_destroy(cmd);
	return (0);
}
