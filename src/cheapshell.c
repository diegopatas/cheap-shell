#include "../incl/minishell.h"
#include <stdlib.h>

int	repl(char *input)
{
	char	**aux;
	t_cmd	*cmd;

	cmd = NULL;
	aux = input_split(input);
	cmd = ds_create();
	cmd->name = aux[0];
	cmd->arg = aux[1];
	if (builtin_check(cmd->name))
		builtin_run(cmd);
	else 
		cmd_run(cmd);
	cmd = ds_destroy(cmd);
	return (0);
}
