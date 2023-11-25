#include "../incl/minishell.h"
#include <stdlib.h>
#include <unistd.h>

char	**vec_create(int size)
{
	char **vec;

	vec = NULL;
	vec = (char **)malloc(size * sizeof(char *));
	ft_bzero(vec, size);
	return (vec);
}

t_cmd	*ds_destroy(t_cmd *cmd)
{
	free(cmd->name);
	free(cmd->arg);
	free(cmd);
	cmd = NULL;
	return (cmd);
}

t_cmd	*ds_create(void)
{
	t_cmd *cmd;

	cmd = NULL;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->name = "echo";
	cmd->arg = NULL;
	cmd->type = NULL;
	cmd->env = NULL;
	cmd->fd = 1;
	cmd->vec = NULL;
	return (cmd);
}
