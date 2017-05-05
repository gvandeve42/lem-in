#include "lem_in.h"

static int	count_way(t_node *end)
{
	int	i;

	i = 0;
	while (end->via[i] != NULL)
		i++;
	return (i);
}

static t_node	*add_way(t_node *start)
{
	int		i;
	int		j;
	t_node	*tmp;

	i = INT_MAX;
	j = 0;
	tmp = NULL;
	while (start->via[j] != NULL)
		{
			if ((start->via[j])->pnd >= 0 &&
				(start->via)[j]->pnd <= i)
				{
					i = (start->via[j])->pnd;
					tmp = start->via[j];
				}
			j++;
		}
	if (i != INT_MAX)
		return (tmp);
	else
		return (NULL);
}

static t_node	*recur_deploy(t_node *init, t_node *end)
{
	t_node	*tmp;

	init->pnd = -1;
	tmp = add_way(init);
	if (tmp == end)
		return (init);
	if (tmp == NULL)
		return (NULL);
	tmp->prec = init;
	return (recur_deploy(tmp, end));
}

static void reinit_tree(t_node *tree)
{
	if (tree == NULL)
		return;
	if (tree->pnd > 0)
		tree->pnd = INT_MAX;
	reinit_tree(tree->link);
}

int		is_startend(t_hive *hv)
{
	t_via *tmp;

	tmp = hv->v_lst;
	while (tmp != NULL)
		{
			if ((strcmp(tmp->n1, hv->start->name) == 0 &&
				 strcmp(tmp->n2, hv->end->name) == 0) ||
				(strcmp(tmp->n2, hv->start->name) == 0 &&
				 strcmp(tmp->n1, hv->end->name) == 0))
				return (1);
			tmp = tmp->link;
		}
	return (0);
}

void	build_way(t_hive *hv)
{
	int		i;
	t_node	*tmp;

	i = 0;
	hv->way = (t_node**)ft_memalloc((count_way(hv->end) + 1) * sizeof(t_node*));
	if (hv->n_lst == NULL || is_startend(hv))
		{
			hv->way[0] = hv->end;
			if (!is_startend(hv))
				{
					ft_printf("Error: Pas de via valide\n");
					exit (1);
				}
			return;
		}
	while ((tmp = add_way(hv->end)) != NULL)
		{
			(hv->way)[i] = recur_deploy(tmp, hv->start);
			add_last((hv->way)[i], hv->end);
			reinit_tree(hv->start);
			expl_via(hv->start, hv->start->via, 0, hv->end);
			i++;
		}
}
