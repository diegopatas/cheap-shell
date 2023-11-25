#include "../incl/minishell.h"
#include <stdlib.h>

char	**input_split(char *input)
{
	return ft_split(input, ' ');
}
