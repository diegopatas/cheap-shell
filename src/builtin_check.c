#include "../incl/minishell.h"

bool	builtin_check(t_ds *ds)
{
	if (ft_strncmp("echo", ds->cmd, ft_strlen(ds->cmd)) == 0)
		return true;
	else if (ft_strncmp("cd", ds->cmd, ft_strlen(ds->cmd)) == 0)
		return true;
	else if (ft_strncmp("pwd", ds->cmd, ft_strlen(ds->cmd)) == 0)
		return true;
	else if (ft_strncmp("export", ds->cmd, ft_strlen(ds->cmd)) == 0)
		return true;
	else if (ft_strncmp("unset", ds->cmd, ft_strlen(ds->cmd)) == 0)
		return true;
	else if (ft_strncmp("env", ds->cmd, ft_strlen(ds->cmd)) == 0)
		return true;
	else if (ft_strncmp("exit", ds->cmd, ft_strlen(ds->cmd)) == 0)
		return true;
	return false;
}
