#include "../incl/minishell.h"
#include <stdlib.h>
#include <unistd.h>

t_cmd	*ds_destroy(t_cmd *cmd)
{
	free(cmd->name);
	free(cmd->arg);
	free(cmd);
	cmd = NULL;
	return (cmd);
}

t_cmd	*ds_create(t_cmd *cmd)
{
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->name = "echo";
	cmd->arg = NULL;
	cmd->type = NULL;
	cmd->env = NULL;
	cmd->fd = 1;
	cmd->vec = (char **)malloc(3 * sizeof(char *));
	cmd->vec[0] = "echo";
	cmd->vec[1] = "txt";
	cmd->vec[2] = NULL;
	return (cmd);
}
