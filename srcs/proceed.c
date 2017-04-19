#include "lem_in.h"
#include <stdio.h>

void	node_proceed(char **tab, t_hive *hv, char *line)
{
	if (is_node(tab, hv, line))
		if (node_viable(tab, hv, line))
			hv->n_lst = new_elem_n(tab[0], tab[1], tab[2], hv->n_lst);
}

void	via_proceed(char **tab, t_hive *hv, char *line)
{
	if (is_via(tab, hv, line))
		if (via_viable(tab, hv, line))
			hv->v_lst = new_elem_v(tab[0], tab[1], hv->v_lst);
}
