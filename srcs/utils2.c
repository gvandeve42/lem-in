/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:57:01 by gvandeve          #+#    #+#             */
/*   Updated: 2017/05/23 15:57:55 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lenn(t_node **node)
{
	int i;

	i = 0;
	while (node[i] != NULL)
		i++;
	return (i);
}

int		llen(t_node *node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		i++;
		node = node->prec;
	}
	return (i);
}

void	recur_print_lst(t_node *nlst)
{
	int		i;

	i = 0;
	if (nlst == NULL)
		return ;
	ft_printf("\n%5s|node : name|%10s||%5d|\n", "", nlst->name, nlst->pnd);
	while (nlst->via[i] != 0)
	{
		ft_printf("%10s|under-node : name|%10s||%5d|\n", "",
					nlst->via[i]->name, nlst->via[i]->pnd);
		i++;
	}
	recur_print_lst(nlst->link);
}

void	print_buff(t_buff *buff)
{
	if (buff == NULL)
	{
		ft_printf("Error\n");
		exit(1);
	}
	else
		while (buff != NULL)
		{
			ft_printf("%s\n", buff->buff);
			buff = buff->next;
		}
	return ;
}
