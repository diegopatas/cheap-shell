#include "../incl/minishell.h"

int main(void){
	t_cmd	*cmd;

	cmd = NULL;
	cmd = ds_create(cmd);
	cmd->arg = "test";
	ft_printf("r: %s\n", fn_wrapper(cmd, &fn_execv));
	return (0);
}
