/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:52:30 by gvandeve          #+#    #+#             */
/*   Updated: 2017/05/23 16:07:01 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_node(t_node *lst)
{
	if (lst != NULL)
	{
		if (lst->link != NULL)
			free_node(lst->link);
		free(lst->name);
		free(lst->via);
		free(lst);
	}
}

void	free_via(t_via *lst)
{
	if (lst != NULL)
	{
		if (lst->link != NULL)
			free_via(lst->link);
		free(lst->n1);
		free(lst->n2);
		free(lst);
	}
}

void	free_hive(t_hive *hive)
{
	free_node(hive->start);
	free_via(hive->v_lst);
	free_buff(hive->buff);
	free(hive->way);
	free(hive);
}

void	free_all(t_hive *hv, char **tab, char *line)
{
	if (hv != NULL)
		free_hive(hv);
	if (tab != NULL)
		free_tab(tab);
	if (line != NULL)
		free(line);
}

void	free_buff(t_buff *buff)
{
	if (buff != NULL)
	{
		if (buff->next != NULL)
			free_buff(buff->next);
		free(buff->buff);
		free(buff);
	}
}
