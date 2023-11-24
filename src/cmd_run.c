#include "../incl/minishell.h"

// char **arr;
// arr[0] = "/bin/cat";
// arr[1] = "test.txt";
// arr[2] = NULL;
//

int	operator_eval(const char *operator)
{
	if (ft_strncmp(operator, ">", 1))
		return (1);
	return (0);
}

int	cmd_run(t_cmd *cmd)
{
	char *seq = ">|||";

	(void)cmd;
	while (*seq) {
		printf("Res: %c \n", *seq);
		seq++;
	}
	return (0);
}
