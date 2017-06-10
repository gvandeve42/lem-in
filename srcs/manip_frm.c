/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_frm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:46:50 by gvandeve          #+#    #+#             */
/*   Updated: 2017/06/10 13:48:57 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_way_end(t_node *way, int ant_start)
{
	if (way->prec == NULL)
	{
		way->ant++;
		ft_printf("L%d-%s ", way->ant, way->name);
		return (1);
	}
	else if (way->prec->prec == NULL && way->ant != 0)
	{
		way->ant++;
		ft_printf("L%d-%s ", way->ant, way->name);
		if (way->ant > ant_start)
			ft_printf("L%d-%s ", way->ant - 1, way->prec->name);
		return (1);
	}
	return (0);
}

void	init_frm(t_node *way, int len, int ant_nb, int ant_start)
{
	way->ant = ant_start;
	ft_printf("L%d-%s ", way->ant, way->name);
	return ;
}

void	pp_frm(t_node *way, int len, int ant_nb, int ant_start)
{
	way->prec->ant = way->ant;
	way->ant++;
	ft_printf("L%d-%s ", way->ant, way->name);
	ft_printf("L%d-%s ", way->prec->ant, way->prec->name);
	return ;
}

void	pr_frm(t_node *way, int len, int ant_nb, int ant_start)
{
	way->ant++;
	ft_printf("L%d-%s ", way->ant, way->name);
}
