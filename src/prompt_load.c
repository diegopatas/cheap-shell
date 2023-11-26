#include "../incl/minishell.h"

char	*prompt_load(char *prev, char **env)
{
	char *curr;
	size_t len;

	(void)env;
	curr = NULL;
	len = ft_strlen(prev);
	curr = (char *)malloc(len);
	ft_strlcpy(curr, prev, len);

	return curr;
}
