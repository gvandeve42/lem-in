/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:05:08 by gvandeve          #+#    #+#             */
/*   Updated: 2017/05/23 16:09:35 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node			*add_end(t_hive *hv)
{
	t_node	*new;
	t_node	*tmp;

	new = hv->end;
	tmp = hv->n_lst;
	if (tmp == NULL)
	{
		hv->start->via = (t_node**)ft_memalloc(2 * sizeof(t_node*));
		hv->end->via = (t_node**)ft_memalloc(2 * sizeof(t_node*));
		hv->start->via[0] = hv->end;
		hv->end->via[0] = hv->start;
		hv->end->pnd = 1;
		return (NULL);
	}
	while (tmp->link != NULL)
		tmp = tmp->link;
	tmp->link = hv->end;
	return (hv->n_lst);
}

t_node			*add_start(t_hive *hv)
{
	t_node	*new;

	new = hv->start;
	new->link = hv->n_lst;
	return (new);
}

int				is_startend(t_hive *hv)
{
	t_via *tmp;

	tmp = hv->v_lst;
	while (tmp != NULL)
	{
		if ((ft_strcmp(tmp->n1, hv->start->name) == 0 &&
			ft_strcmp(tmp->n2, hv->end->name) == 0) ||
			(ft_strcmp(tmp->n2, hv->start->name) == 0 &&
			ft_strcmp(tmp->n1, hv->end->name) == 0))
			return (1);
		tmp = tmp->link;
	}
	return (0);
}

void			free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		free(tab[i++]);
	free(tab);
}

int				len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}
