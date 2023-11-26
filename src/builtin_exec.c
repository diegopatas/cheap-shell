#include "../incl/minishell.h"

int	fn_match(char *expect, char *given) 
{
	return ft_strncmp(expect, given, ft_strlen(given));
}

int	builtin_exec(t_cmd *cmd)
{
	if (fn_match("echo", cmd->name))
		return cmd_echo(cmd);
	if (fn_match("cd", cmd->name))
		return cmd_cd(cmd);
	if (fn_match("pwd", cmd->name))
		return cmd_pwd(cmd);
	if (fn_match("export", cmd->name))
		return cmd_export(cmd);
	if (fn_match("unset", cmd->name))
		return cmd_unset();
	if (fn_match("env", cmd->name))
		return cmd_env();
	if (fn_match("exit", cmd->name))
		return cmd_exit();
	return (0);
}
