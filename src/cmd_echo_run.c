#include "../incl/minishell.h"

int cmd_echo(t_ds *ds)
{
	ft_printf("%s\n", ds->arg);
	return (0);
}
