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
	recur_deploy(tmp, end);
}

static void reinit_tree(t_node *tree)
{
	if (tree == NULL)
		return;
	if (tree->pnd > 0)
		tree->pnd = INT_MAX;
	reinit_tree(tree->link);
}

void	build_way(t_hive *hv)
{
	int		i;
	t_node	*tmp;

	i = 0;
	hv->way = (t_node**)ft_memalloc((count_way(hv->end) + 1) * sizeof(t_node*));
	while ((tmp = add_way(hv->end)) != NULL)
		{
			(hv->way)[i] = recur_deploy(tmp, hv->start);
			add_last((hv->way)[i], hv->end);
			reinit_tree(hv->start);
			expl_via(hv->start, hv->start->via, 0, hv->end);
			i++;
		}
	i = 0;
	while ((hv->way)[i] != NULL)
		print_lst_p((hv->way)[i++]);
}
