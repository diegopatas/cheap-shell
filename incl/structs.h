#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_cmd {
	char *name;
	char *arg;
	char *type;
	char **env;
	char **vec;
	int  fd;
}	t_cmd;

typedef struct s_sh {
	char *cmd;
	char **env;
	char *input;
} t_sh;

# endif
