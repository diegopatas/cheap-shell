/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:58:57 by ddiniz            #+#    #+#             */
/*   Updated: 2023/09/06 12:27:03 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// allowed libraries
# include "../lib/libft.h"
# include <readline/readline.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdbool.h>

#define READ_EDGE 0
#define WRITE_EDGE 1

typedef struct s_cmd {
	char *name;
	char *arg;
	char *type;
	char **env;
	char **vec;
	int  fd;
}	t_cmd;

int	cheapshell(char *input);
t_cmd	*ds_destroy(t_cmd *cmd);
t_cmd	*ds_create(t_cmd *cmd);

char	**input_split(char *input);

bool	builtin_check(const char *cmd);
int	builtin_run(t_cmd *cmd);
int	echo_run(t_cmd *cmd);
int	exit_run(void);
int	unset_run(void);
int	cd_run(t_cmd *cmd);
int	env_run(void);
int	pwd_run(void);
int	export_run(t_cmd *cmd);

int	cmd_run(t_cmd *cmd);

char	*fn_wrapper(t_cmd *cmd, int (*fn)());
int	fn_execv(t_cmd *cmd);

#endif
