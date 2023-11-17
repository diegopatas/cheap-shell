#ifndef MINISHELL_TEMP_H
# define MINISHELL_TEMP_H

#include <stdbool.h>
// TEMPORARY FUNCTIONS

typedef struct s_ds {
	char *cmd;
	char *arg;
	char **env;
} t_ds;

char	**input_split(char *input);
bool	builtin_check(char *cmd);
int	builtin_run(t_ds *ds);
int	cmd_run(t_ds *ds);
int 	cmd_echo(t_ds *ds);
t_ds	*ds_destroy(t_ds *ds);
t_ds	*ds_create(t_ds *ds);

#endif
