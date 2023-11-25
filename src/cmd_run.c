#include "../incl/minishell.h"

static int	operator_eval(const char *operator)
{
	if (ft_strncmp(operator, ">", 1))
		return (OPER_WRITE);
	if (ft_strncmp(operator, "|", 1))
		return (OPER_PIPE);
	return (0);
}

int	cmd_run(t_cmd *cmd)
{
	char *seq = ">|||";

	(void)cmd;
	// char *target = "cat echoed.txt > void.txt | sort | tail -n 3 | grep pirate";

	while (*seq) {
		if (operator == OPER_WRITE)
			cmd_run_redirect();
		else if (operator == OPER_PIPE)
			cmd_run_pipe(aux_pipe);
		seq++;
	}
	return (0);
}
