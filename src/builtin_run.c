#include "../incl/minishell.h"

int	builtin_match(char *expect, char *given) 
{
	return ft_strncmp(expect, given, ft_strlen(given));
}

int	builtin_run(t_cmd *cmd)
{
	if (builtin_match("echo", cmd->name))
		return echo_run(cmd);
	if (builtin_match("cd", cmd->name))
		return cd_run(cmd);
	if (builtin_match("pwd", cmd->name))
		return pwd_run();
	if (builtin_match("export", cmd->name))
		return export_run(cmd);
	if (builtin_match("unset", cmd->name))
		return unset_run();
	if (builtin_match("env", cmd->name))
		return env_run();
	if (builtin_match("exit", cmd->name))
		return exit_run();
	return (0);
}
