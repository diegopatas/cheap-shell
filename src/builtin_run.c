#include "../incl/minishell.h"
#include <stdlib.h>
#include <unistd.h>

int cmd_pwd(void)
{
	char *pwd = getcwd(NULL, 256);
	ft_printf("%s\n", pwd);
	free(pwd);
	return (0);
}

int cmd_cd(t_ds *ds)
{
	if (chdir(ds->arg) == -1)
		ft_printf("bash: %s: %s: No such file or directory\n", ds->cmd, ds->arg);

	cmd_pwd();
	return (0);
}

int cmd_env(void)
{
	return (0);
}

int cmd_export(t_ds *ds)
{
	int i;

	i = 0;
	while (ds->env[i++] != NULL)
		;
	ft_printf("%d\n", i);
	ds->env[i] = "test";
	ft_printf("%s\n", ds->env[i]);
	return (0);
}

int cmd_unset(void)
{
	return (0);
}

int cmd_exit(void)
{
	return (0);
}

int	builtin_run(t_ds *ds)
{
	if (ft_strncmp("echo", ds->cmd, ft_strlen(ds->cmd)) == 0)
		return cmd_echo(ds);
	else if (ft_strncmp("cd", ds->cmd, ft_strlen(ds->cmd)) == 0)
		return cmd_cd(ds);
	else if (ft_strncmp("pwd", ds->cmd, ft_strlen(ds->cmd)) == 0)
		return cmd_pwd();
	else if (ft_strncmp("export", ds->cmd, ft_strlen(ds->cmd)) == 0)
		return cmd_export(ds);
	else if (ft_strncmp("unset", ds->cmd, ft_strlen(ds->cmd)) == 0)
		return cmd_unset();
	else if (ft_strncmp("env", ds->cmd, ft_strlen(ds->cmd)) == 0)
		return cmd_env();
	else if (ft_strncmp("exit", ds->cmd, ft_strlen(ds->cmd)) == 0)
		return cmd_exit();
	return (0);
}
