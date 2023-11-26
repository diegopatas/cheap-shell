#include "../incl/minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	// char	*prompt;
	t_sh	*shell;

	// prompt = NULL;
	shell = NULL;
	signal_handler();
	if (argc == 1) 
	{
		shell = shell_load();
		ft_printf("s: %s\n", env[0]);
		// shell->env = env_load(env);
		while (1)
		{
			// prompt = prompt_load("cheap-shell: ", shell->env);
			shell->input = readline("mini$: ");
			if (shell_repl(shell) != 0)
				break ;
		}
	}
	else 
		ft_printf("Panic! %s has an invalid number of arguments\n", argv[0]);
	return (0);
}
