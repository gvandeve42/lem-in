#include "lem_in.h"
#include <stdio.h>

void	node_proceed(char **tab, t_hive *hv)
{
	if (is_node(tab))
		hv->lst = new_elem(tab[0], tab[1], tab[2], hv->lst);
}

void	via_proceed(char **tab, t_hive *hv)
{
	if (is_via(tab))
		printf("VIA GOOD\n");
}
