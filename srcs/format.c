/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:38:39 by gvandeve          #+#    #+#             */
/*   Updated: 2017/05/23 15:41:48 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char			*get_name(t_node *node, int nb)
{
	while (nb-- > 0)
		node = node->prec;
	return (node->name);
}

static int		get_max(int *nbl)
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

static void		set_nbf(int *nbf, int *nbl, int max, int ant)
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

static void		error_print(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void			format(t_hive *hv)
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
		i++;
	}
	max = get_max(nbl);
	if ((hv->way)[0] != NULL)
		set_nbf(nbf, nbl, max, hv->ant);
	else
		error_print();
	print_buff(hv->buff);
	format_rsp(hv, nbl, nbf);
	free(nbl);
	free(nbf);
}
