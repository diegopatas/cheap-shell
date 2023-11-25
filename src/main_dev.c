#include "../incl/minishell.h"

int main(void){
	t_cmd	*cmd;

	cmd = NULL;
	cmd = ds_create();
	cmd->arg = "test";
	cmd->vec = vec_create(3);
	cmd->vec[0] ="echo";
	cmd->vec[1] = cmd->arg;
	ft_printf("r: %s\n", fn_wrapper(cmd, &fn_execv));
	return (0);
}
