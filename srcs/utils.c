/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:55:25 by gvandeve          #+#    #+#             */
/*   Updated: 2017/06/05 13:46:43 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_lst_p(t_node *lst)
{
	if (lst != NULL)
	{
		ft_printf("|||NODE : %10s, %10d, %10d, %10d|||\n",
					lst->name, lst->x, lst->y, lst->pnd);
		print_lst_p(lst->prec);
	}
}

void	print_lst_n(t_node *lst)
{
	if (lst != NULL)
	{
		ft_printf("|||NODE : %10s, %10d, %10d|||\n", lst->name, lst->x, lst->y);
		print_lst_n(lst->link);
	}
}

void	print_lst_v(t_via *lst)
{
	if (lst != NULL)
	{
		ft_printf("|||VIA  : %10s, %10s|||\n", lst->n1, lst->n2);
		print_lst_v(lst->link);
	}
}

void	scrap_ant(t_hive *hv, char **line)
{
	static char	flag;

	if (flag != 42)
	{
		flag = 42;
		if (is_nb(*line) &&
			ft_atoi(*line) > 0 &&
			ft_atoi(*line) <= 2147483600)
		{
			hv->buff = new_elem_b(*line, hv->buff);
			hv->ant = ft_atoi(*line);
			free(*line);
			get_next_line(0, line);
		}
		else
		{
			ft_putstr_fd("Error : ant number bad formated or too big\n", 2);
			exit(1);
		}
	}
}

int		count_via(t_node *nlst, t_via *vlst)
{
	int		nbvia;

	nbvia = 0;
	while (vlst != NULL)
	{
		if (ft_strcmp(vlst->n1, nlst->name) == 0 ||
			ft_strcmp(vlst->n2, nlst->name) == 0)
			nbvia++;
		vlst = vlst->link;
	}
	return (nbvia);
}
