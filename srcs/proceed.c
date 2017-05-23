/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:55:15 by gvandeve          #+#    #+#             */
/*   Updated: 2017/05/23 15:55:18 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	node_proceed(char **tab, t_hive *hv, char *line)
{
	if (is_node(tab, hv, line))
		if (node_viable(tab, hv, line))
			hv->n_lst = new_elem_n(tab[0], tab[1], tab[2], hv->n_lst);
}

void	via_proceed(char **tab, t_hive *hv, char *line)
{
	if (is_via(tab, hv, line))
		if (node_exist(tab, hv))
			hv->v_lst = new_elem_v(tab[0], tab[1], hv->v_lst);
}
