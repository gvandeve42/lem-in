#include "lem_in.h"

void	recur_print_lst(t_node *nlst)
{
	int		i;

	i = 0;
	if (nlst == NULL)
		return;
	ft_printf("|node : %s|\n", nlst->name);
	while (nlst->via[i] != 0)
		{
			ft_printf("|   under->node : %s\n", nlst->via[i]->name);
			i++;
		}
	recur_print_lst(nlst->link);
}
