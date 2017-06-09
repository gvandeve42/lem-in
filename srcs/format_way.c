/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 10:53:56 by gvandeve          #+#    #+#             */
/*   Updated: 2017/05/23 16:02:38 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		push_frm(t_node *way, int len, int ant_nb, int ant_start)
{
	if (ant_nb > 0)
	{
		if (way->prec == NULL)
			{
				way->ant++;
				ft_printf("L%d-%s ", way->ant, way->name);
				return ;
			}
		else if (way->prec->prec == NULL)
		{
			way->ant++;
			ft_printf("L%d-%s ", way->ant, way->name);
			if (way->ant > ant_start)
				ft_printf("L%d-%s ", way->ant - 1, way->prec->name);
			return ;
		}
		else if (way->prec->ant == 0 && way->ant == 0)
		{
			init_frm(way, len, ant_nb, ant_start);
			return ;
		}
		else if (way->prec->ant == 0 && way->ant != 0)
		{
			pp_frm(way, len, ant_nb, ant_start);
			return ;
		}
		else if (way->prec->ant != 0 && way->ant != 0)
			pr_frm(way, len, ant_nb, ant_start);
	}
	else
		return ;
	push_frm(way->prec, len, ant_nb, ant_start);
	return ;
}

static void		free_frm(t_node *way, int bef)
{
	int tmp;

	tmp = 0;
	if (way == NULL)
		return ;
	tmp = way->ant;
	way->ant = bef;
	if (way->ant > 0)
		ft_printf("L%d-%s ", way->ant, way->name);
	free_frm(way->prec, tmp);
	return ;
}

static int		sum(int *tab, int len)
{
	int	i;
	int rtn;

	i = 0;
	rtn = 0;
	while (i < len)
		rtn += tab[i++];
	return (rtn);
}

static void		format_way(t_hive *hv, int *len, int *ant_nb, int *ant_start)
{
	int		j;

	j = 0;
	while ((sum(ant_nb, lenn(hv->way)) + sum(len, lenn(hv->way)) > 0))
	{
		ft_printf("\n");
		while ((hv->way)[j] != NULL)
		{
			if (ant_nb[j] > 0)
			{
				push_frm((hv->way)[j], len[j], ant_nb[j], ant_start[j]);
				ant_nb[j]--;
			}
			else if (len[j] > 0)
			{
				free_frm((hv->way)[j], 0);
				len[j]--;
			}
			j++;
		}
		j = 0;
	}
}

void			format_rsp(t_hive *hv, int *nbl, int *nbf)
{
	int		frm[lenn(hv->way) + 1];
	int		i;

	i = 0;
	while (nbf[i] != 0)
	{
		frm[i] = (i == 0) ? 1 : nbf[i - 1] + frm[i - 1];
		i++;
	}
	format_way(hv, nbl, nbf, frm);
}
