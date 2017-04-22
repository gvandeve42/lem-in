#include "lem_in.h"

static int is_good(t_node *node, int pnd)
{
	if (pnd > node->pnd)
		return (0);
	node->pnd = pnd;
	return (1);
}

static void	expl_via(t_node *lst, t_node **vlst, int pnd, t_node *end)
{
	if (lst == end || lst == 0)
		return;
	if (*vlst != 0)
		{
			if (is_good(*vlst, pnd))
				expl_via(*vlst, (*vlst)->via, pnd + 1, end);
			else
				expl_via(lst, (lst->via + 1), pnd, end);
		}
	return;
}

void	enter_calc(t_hive *hv)
{
	if (hv->start == NULL ||
		hv->end == NULL ||
		hv->n_lst == NULL ||
		hv->v_lst == NULL)
		{
			ft_printf("Error : File incomplete\n");
			exit (1);
		}
	else
		{
			build_web(hv);
			expl_via(hv->start, hv->start->via, 1, hv->end);
		}
}
