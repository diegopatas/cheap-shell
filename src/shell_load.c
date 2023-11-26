#include "../incl/minishell.h"
#include <stdlib.h>

t_sh	*shell_load(void)
{
	t_sh *shell;

	shell = NULL;
	shell = (t_sh *)malloc(sizeof(t_sh));
	ft_bzero(shell, sizeof(t_sh));
	return shell;
}
