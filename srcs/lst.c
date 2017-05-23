/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:54:32 by gvandeve          #+#    #+#             */
/*   Updated: 2017/05/23 15:54:47 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_last(t_node *node, t_node *add)
{
	while (node->prec != NULL)
		node = node->prec;
	node->prec = add;
}

t_node	*new_elem_n(char *name, char *x, char *y, t_node *nd)
{
	t_node	*anchor;

	anchor = nd;
	if (nd == NULL)
	{
		nd = init_node(name, x, y);
		return (nd);
	}
	else
	{
		while (nd->link != NULL)
			nd = nd->link;
		nd->link = init_node(name, x, y);
	}
	return (anchor);
}

t_via	*new_elem_v(char *name1, char *name2, t_via *via)
{
	t_via	*anchor;

	anchor = via;
	if (via == NULL)
	{
		via = init_via(name1, name2);
		return (via);
	}
	else
	{
		while (via->link != NULL)
			via = via->link;
		via->link = init_via(name1, name2);
	}
	return (anchor);
}

t_buff	*new_elem_b(char *line, t_buff *buff)
{
	t_buff	*anchor;

	anchor = buff;
	if (buff == NULL)
	{
		buff = init_buff(line);
		return (buff);
	}
	else
	{
		while (buff->next != NULL)
			buff = buff->next;
		buff->next = init_buff(line);
	}
	return (anchor);
}
