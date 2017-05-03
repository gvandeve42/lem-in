/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:25:22 by gvandeve          #+#    #+#             */
/*   Updated: 2017/05/02 10:49:39 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_start(char **tab, t_hive *hv, char *line)
{
	if (len(tab) == 3 && is_node(tab, hv, line))
		{
			if (node_viable(tab, hv, line))
				{
					hv->start = new_elem_n(tab[0], tab[1], tab[2], hv->start);
					hv->start->pnd = 0;
				}
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

static int	search_node(char *name, t_node *lst)
{
	if (lst == NULL)
		return (0);
	if (ft_strcmp(name, lst->name) == 0)
		return (1);
	return (search_node(name, lst->link));
}

int		node_exist(char **name_tab, t_hive *hv)
{
	if (hv->start != NULL &&
		hv->end != NULL &&
		hv->n_lst != NULL)
		{
			if (((ft_strcmp(name_tab[0], hv->start->name) != 0 &&
				  ft_strcmp(name_tab[0], hv->end->name) != 0) &&
				 !search_node(name_tab[0], hv->n_lst)) ||
				((ft_strcmp(name_tab[1], hv->start->name) != 0 &&
				  ft_strcmp(name_tab[1], hv->end->name) != 0) &&
				 !search_node(name_tab[1], hv->n_lst)))
				{
					free_all(hv, name_tab, NULL);
					ft_printf("Error : Via between nodes that don't exist\n");
					exit (1);
				}
			else
				return (1);
		}
	return (0);

}


















