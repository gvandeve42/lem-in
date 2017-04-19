/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:25:22 by gvandeve          #+#    #+#             */
/*   Updated: 2017/04/19 14:42:20 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_start(char **tab, t_hive *hv, char *line)
{
	if (len(tab) == 3 && is_node(tab, hv, line))
		{
			if (node_viable(tab, hv, line))
				hv->start = new_elem_n(tab[0], tab[1], tab[2], hv->start);
		}
		else
		{
			free_all(hv, tab, line);
			ft_printf("Error : Start bad formatted\n");
			exit (1);
		}
}

void	check_end(char **tab, t_hive *hv, char *line)
{
	if (len(tab) == 3 && is_node(tab, hv, line))
		{
			if (node_viable(tab, hv, line))
				hv->end = new_elem_n(tab[0], tab[1], tab[2], hv->end);
		}
		else
		{
			free_all(hv, tab, line);
			ft_printf("Error : End bad formatted\n");
			exit (1);
		}
}




















