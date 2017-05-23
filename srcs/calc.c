/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:32:09 by gvandeve          #+#    #+#             */
/*   Updated: 2017/05/23 15:33:24 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	is_good(t_node *node, int pnd)
{
	if (pnd > node->pnd)
		return (0);
	node->pnd = pnd;
	return (1);
}

void		expl_via(t_node *lst, t_node **vlst, int pnd, t_node *end)
{
	if (lst == end)
		return ;
	if (*vlst == NULL)
		return ;
	if (is_good(*vlst, pnd + 1))
		expl_via(*vlst, (*vlst)->via, pnd + 1, end);
	expl_via(lst, ++vlst, pnd, end);
}

void		enter_calc(t_hive *hv)
{
	if (hv->start == NULL ||
		hv->end == NULL ||
		hv->v_lst == NULL)
	{
		ft_putstr_fd("Error : File incomplete\n", 2);
		exit(1);
	}
	else
	{
		build_web(hv);
		expl_via(hv->start, hv->start->via, 0, hv->end);
		build_way(hv);
		format(hv);
	}
}
