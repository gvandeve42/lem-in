/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 10:53:56 by gvandeve          #+#    #+#             */
/*   Updated: 2017/05/03 18:22:45 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	push_frm(t_node *way, int len, int ant_nb, int ant_start)
{
	if (way->prec->ant == 0 && way->ant == 0)
	{
		way->ant = ant_start;
		printf("L%d-%s ", way->ant, way->name);
		return;
	}
	else if (way->prec == NULL && way->ant != 0)
	{
		way->ant++;
		printf("L%d-%s ", way->ant, way->name);
		return ;
	}
	else if (way->prec->ant != 0 && way->ant != 0)
	{
		way->ant++;
		printf("L%d-%s ", way->ant, way->name);
	}
	else if (way->prec->ant == 0 && way->ant != 0)
	{
		way->prec->ant = way->ant;
		way->ant++;
		printf("L%d-%s ", way->ant, way->name);
	}

}

static void	format_way(t_hive *hv, int *len, int *ant_nb, int *ant_start)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < hv->ant)
	{
		while ((hv->way)[j] != NULL)
		{
			if (ant_nb[j] > 0)
			{
				push_frm((hv->way)[j], len[j], ant_nb[j], ant_start[j]);
				ant_nb[j]--;
			}
			//else
			//	free_frm((hv->way)[j], len[j], ant_nb[j], ant_start[j]);
			ft_printf("\n");
			j++;
		}
		i++;
		j = 0;
	}
}

void	format_rsp(t_hive *hv, int *nbl, int *nbf)
{
	int		frm[lenn(hv->way) + 1];
	int		i;

	i = 0;
	while (nbf[i] != 0)
	{
		frm[i] = (i == 0) ? 1 : nbf[i - 1];
		i++;
	}
	format_way(hv, nbl, nbf, frm);
}


