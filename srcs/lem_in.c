/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 12:16:00 by gvandeve          #+#    #+#             */
/*   Updated: 2017/04/15 12:20:44 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static void	scrap_info(char **line, t_hive *hv)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(*line, ' ');
	if (len(tab) == 3)
		node_proceed(tab, hv);
	else
		{
			free_tab(tab);
			tab = ft_strsplit(*line, '-');
			if (len(tab) == 2)
				via_proceed(tab, hv);
			else
				{
					ft_printf("Error : File bad formatted\n");
					exit(1);
				}
		}
	free_tab(tab);
}

static void	scrap_start(char **line, t_hive *hv)
{
	char	**tab;

	free(*line);
	get_next_line(0, line);
	tab = ft_strsplit(*line, ' ');
	hv->start = new_elem(tab[0], tab[1], tab[2], hv->start);
	ft_printf("|||START : %10s, %10d, %10d|||\n", hv->start->name, hv->start->x, hv->start->y);
	free_tab(tab);
	free(*line);
	get_next_line(0, line);
}

static void	scrap_end(char **line, t_hive *hv)
{
	char	**tab;

	free(*line);
	get_next_line(0, line);
	tab = ft_strsplit(*line, ' ');
	hv->end = new_elem(tab[0], tab[1], tab[2], hv->end);
	ft_printf("|||END   : %10s, %10d, %10d|||\n", hv->end->name, hv->end->x, hv->end->y);
	free_tab(tab);
	free(*line);
	get_next_line(0, line);
}

int		main(void)
{
	char	*line;
	t_hive	*hive;

	hive = (t_hive*)ft_memalloc(sizeof(t_hive));
	while (get_next_line(0, &line))
		{
			ft_printf("String : %s\n", line);
			if (ft_strncmp(line, "##start", 7) == 0)
				scrap_start(&line, hive);
			else if (ft_strncmp(line, "##end", 5) == 0)
				scrap_end(&line, hive);
			if (ft_strncmp(line, "#", 1) != 0)
				scrap_info(&line, hive);
			free(line);
		}
	print_lst(hive->lst);
	free_hive(hive);
	return (0);
}




















