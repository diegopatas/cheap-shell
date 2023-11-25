#include "../incl/minishell.h"

int	fn_execv(t_cmd *cmd) 
{
	char	*root;

	root = ft_strjoin("/bin/", cmd->name);
	execve(root, cmd->vec, NULL);
	return (0);
}
