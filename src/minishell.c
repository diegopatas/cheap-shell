#include "../incl/minishell.h"
#include <stdlib.h>

int	main(int argc, char *argv[], char *env[])
{
	char	*user_input;
	char	**aux;
	t_ds	*ds;

	user_input = NULL;
	ds = NULL;
	ds = ds_create(ds);
	if (argc == 1) 
	{
		while (1)
		{
			user_input = readline("minishell$ ");
			aux = input_split(user_input);
			ds->cmd = aux[0];
			ds->arg = aux[1];
			ds->env = env;
			if (builtin_check(ds->cmd))
			{
				builtin_run(ds);
				break ;
			}
			else if (ds->cmd != NULL)
			{
				cmd_run(ds);
				break ;

			}
			ft_printf("Panic! Command \"%s\" is invalid...\nTry: \"echo\"\n", ds->cmd[0]);
		}
	}
	else 
		ft_printf("Panic! %s has an invalid number of arguments\n", argv[0]);
		
	free(ds->cmd);
	free(ds->arg);
	ds = ds_destroy(ds);
	return (0);
}
