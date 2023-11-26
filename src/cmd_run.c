#include "../incl/minishell.h"

int	cmd_run(t_cmd *cmd)
{
	// char *target = "cat echoed.txt > void.txt | sort | tail -n 3 | grep pirate";

	pipeln_exec(cmd);
	return (0);
}
