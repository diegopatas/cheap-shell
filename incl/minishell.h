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
# include "../incl/structs.h"
# include <readline/readline.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdbool.h>

#define READ_EDGE 0
#define WRITE_EDGE 1

int	shell_repl(t_sh *shell);
t_sh	*shell_load(void);

bool	builtin_check(const char *cmd);
int	builtin_exec(t_cmd *cmd);
int	cmd_cd(t_cmd *cmd);
int	cmd_echo(t_cmd *cmd);
int	cmd_export(t_cmd *cmd);
int	cmd_unset(void);
int	cmd_pwd(t_cmd *cmd);
int	cmd_exit(void);
int	cmd_env(void);
int	cmd_unset(void);

int	cmd_run(t_cmd *cmd);

char	*fn_wrap_fd(t_cmd *cmd, int (*fn)());
int	fn_execv(t_cmd *cmd);

// EXECUTION FUNCTIONS
int	pipeln_exec(t_cmd *cmd);
int	redirect_exec(void);

int	signal_handler(void);

char	**env_load(char *env[]);

char	*prompt_load(char *curr, char **env);

// DEV AND TESTS
t_cmd	*ds_destroy(t_cmd *cmd);
t_cmd	*ds_create(void);
char	**vec_create(int size);

# endif
