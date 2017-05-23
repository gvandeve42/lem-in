/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_frm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:46:50 by gvandeve          #+#    #+#             */
/*   Updated: 2017/05/23 16:03:29 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
