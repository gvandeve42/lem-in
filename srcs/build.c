/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:22:33 by gvandeve          #+#    #+#             */
/*   Updated: 2017/05/23 16:05:58 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_via(char *nd_name, t_node *start, char *name)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = start;
	while (ft_strcmp(tmp->name, nd_name) != 0)
		tmp = tmp->link;
	while (start != NULL)
	{
		if (ft_strcmp(start->name, name) == 0)
		{
			while (tmp->via[i] != 0)
			{
				if (tmp->via[i]->name == start->name)
					break ;
				else
					i++;
			}
			tmp->via[i] = start;
		}
		start = start->link;
	}
}

static void		search_via(t_node *nlst, t_node *start, t_via *vlst)
{
	if (vlst == NULL)
		return ;
	if (ft_strcmp(vlst->n1, nlst->name) == 0)
	{
		add_via(nlst->name, start, vlst->n2);
		add_via(vlst->n2, start, nlst->name);
	}
	if (ft_strcmp(vlst->n2, nlst->name) == 0)
	{
		add_via(nlst->name, start, vlst->n1);
		add_via(vlst->n1, start, nlst->name);
	}
	search_via(nlst, start, vlst->link);
}

static void		recur_via(t_node *nlst, t_node *start, t_via *vlst)
{
	if (nlst == NULL)
		return ;
	else
		search_via(nlst, start, vlst);
	recur_via(nlst->link, start, vlst);
}

static void		init_all_nodes(t_node *nlst, t_via *vlst)
{
	if (nlst == NULL)
		return ;
	else
		nlst->via = (t_node**)ft_memalloc((count_via(nlst, vlst) + 1)
													* sizeof(t_node*));
	init_all_nodes(nlst->link, vlst);
}

void			build_web(t_hive *hv)
{
	add_start(hv);
	if (add_end(hv) == NULL)
		return ;
	init_all_nodes(hv->start, hv->v_lst);
	recur_via(hv->start, hv->start, hv->v_lst);
	return ;
}
