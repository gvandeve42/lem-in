#include "lem_in.h"

static int	count_way(t_node *end)
{
	int	i;

	i = 0;
	while (end->via[i] != NULL)
		i++;
	return (i);
}

static int	add_way(t_node **way, t_node *start)
{
	int		i;
	int		j;

	i = INT_MAX;
	j = 0;
	while (start->via[j] != NULL)
		{
			if ((start->via[j])->pnd >= 0 &&
				(start->via)[j]->pnd <= i)
				{
					i = (start->via[j])->pnd;
					*way = start->via[j];
				}
			j++;
		}
	if (i != INT_MAX)
		return (1);
	else
		return (0);
}

static int	recur_deploy(t_node *init, t_node *end)
{
	if (init == end)
		return (1);
	if (add_way(&(init->prec), init))
		{
			if (init->prec->pnd > 0)
				init->prec->pnd = -1;
			recur_deploy(init->prec, end);
		}
}

void	build_way(t_hive *hv)
{
	t_node	**way;
	int		i;

	i = 0;
	way = (t_node**)ft_memalloc((count_way(hv->end) + 1) * sizeof(t_node*));
	while (add_way(&way[i], hv->end))
		{
			way[i]->pnd = -1;
			i++;
		}
	i = 0;
	while (way[i] != NULL)
		{
			//expl_via(hv->start, hv->start->via, 0, hv->end);
			//recur_print_lst(hv->start);
			if (recur_deploy(way[i], hv->start))
				{
					print_lst_p(way[i]);
					i++;
				}
		}
	//purge(way);
	free(way);
}
