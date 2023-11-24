#include "../incl/minishell.h"

int pwd_run(void)
{
	char *pwd = getcwd(NULL, 256);
	ft_printf("%s\n", pwd);
	free(pwd);
	return (0);
}
