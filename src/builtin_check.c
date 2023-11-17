#include "../incl/minishell.h"

bool	builtin_check(char *cmd)
{
	if (ft_strncmp("echo", cmd, ft_strlen(cmd)) == 0)
		return true;
	else if (ft_strncmp("cd", cmd, ft_strlen(cmd)) == 0)
		return true;
	else if (ft_strncmp("pwd", cmd, ft_strlen(cmd)) == 0)
		return true;
	else if (ft_strncmp("export", cmd, ft_strlen(cmd)) == 0)
		return true;
	else if (ft_strncmp("unset", cmd, ft_strlen(cmd)) == 0)
		return true;
	else if (ft_strncmp("env", cmd, ft_strlen(cmd)) == 0)
		return true;
	else if (ft_strncmp("exit", cmd, ft_strlen(cmd)) == 0)
		return true;
	return false;
}
