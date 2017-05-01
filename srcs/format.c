#include "lem_in.h"

static char	*get_name(t_node *node, int nb)
{
	while (nb-- > 0)
		node = node->prec;
	return (node->name);
}

static void	format_way(t_node *way, int ant)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i <= ant)
		{
			while (j < i)
				{
					if (j < llen(way))
						ft_printf("L%d-%s ", (i - j), get_name(way, (j)));
					j++;
				}
			ft_printf("\n");
			j = 0;
			i++;
		}
}

static int	get_max(int	*nbl)
{
	int	i;
	int	rsp;

	i = 0;
	rsp = 0;
	while (nbl[i] != 0)
		{
			if (nbl[i] > rsp)
				rsp = nbl[i];
			i++;
		}
	return (rsp);
}

static void	set_nbf(int *nbf, int *nbl, int max, int ant)
{
	int	i;

	i = 0;
	while (nbl[i] != 0)
		{
			nbf[i] = max - nbl[i];
			ant -= max - nbl[i];
			i++;
		}
	i = 0;
	while (ant > 0)
		{
			while (nbl[i] != 0 && ant > 0)
				{
					nbf[i]++;
					ant--;
					i++;
				}
			i = 0;
		}
}

void	format(t_hive *hv)
{
	int	i;
	int	max;
	int	*nbl;
	int	*nbf;

	i = 0;
	max = 0;
	nbl = (int*)ft_memalloc((lenn(hv->way) + 1) * sizeof(int));
	nbf = (int*)ft_memalloc((lenn(hv->way) + 1) * sizeof(int));
	while ((hv->way)[i] != NULL)
		{
			nbl[i] = llen((hv->way)[i]);
			ft_printf("NBL %d\n", nbl[i]);
			i++;
		}
	max = get_max(nbl);
	set_nbf(nbf, nbl, max, hv->ant);
	i = 0;
	while (nbl[i] != 0)
		{
			ft_printf("RSP %d %d\n", i, nbf[i]);
			i++;
		}
	free(nbl);
	free(nbf);
}
