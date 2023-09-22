#include "../incl/minishell.h"
#include <stdlib.h>

t_ds	*ds_destroy(t_ds *ds)
{
	free(ds);
	ds = NULL;
	return (ds);
}

t_ds	*ds_create(t_ds *ds)
{
	ds = (t_ds *)malloc(sizeof(t_ds));
	ds->cmd = NULL;
	ds->arg = NULL;
	return (ds);
}
