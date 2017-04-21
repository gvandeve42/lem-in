#include "lem_in.h"

static t_node *add_end(t_hive *hv)
{
	t_node	*new;
	t_node	*tmp;

	new = hv->end;
	tmp = hv->n_lst;
	while (tmp->link != NULL)
		tmp = tmp->link;
	tmp->link = hv->end;
	return (hv->n_lst);
}

static t_node *add_start(t_hive *hv)
{
	t_node	*new;

	new = hv->start;
	new->link = hv->n_lst;
	return (new);
}

static void		build_via(t_node *n_lst, t_via *v_lst)
{
	int		nb_via;

	nb_via = count_via(n_lst, v_lst);
	ft_printf("||| NB_VIA = %d|||\n", nb_via);
}

void	build_web(t_hive *hv)
{
	add_start(hv);
	add_end(hv);
	build_via(hv->start, hv->v_lst);
}
