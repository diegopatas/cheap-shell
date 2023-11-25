#include "../incl/minishell.h"
#include <stdlib.h>

int	main(int argc, char *argv[], char *env[])
{
	char	*user_input;

	user_input = NULL;
	(void)env;
	if (argc == 1) 
	{
		while (1)
		{
			user_input = readline("minishell$ ");
			if (cheapshell(user_input) != 0)
				break ;
		}
	}
	else 
		ft_printf("Panic! %s has an invalid number of arguments\n", argv[0]);
	return (0);
}
