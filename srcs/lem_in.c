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

static void	scrap_start(char **line, t_hive *hv)
{
	char	**tab;
	int		i;

	i = 0;
	free(*line);
	get_next_line(0, line);
	tab = ft_strsplit(*line, ' ');
	hv->start = new_elem(tab[0], tab[1], tab[2], hv->start);
	ft_printf("|||START : %10s, %10d, %10d|||\n", hv->start->name, hv->start->x, hv->start->y);
	while (tab[i] != 0)
		free(tab[i++]);
	free(tab);
	free(*line);
	get_next_line(0, line);
}

static void	scrap_end(char **line, t_hive *hv)
{
	char	**tab;
	int		i;

	i = 0;
	free(*line);
	get_next_line(0, line);
	tab = ft_strsplit(*line, ' ');
	hv->end = new_elem(tab[0], tab[1], tab[2], hv->end);
	ft_printf("|||END   : %10s, %10s, %10s|||\n", tab[0], tab[1], tab[2]);
	while (tab[i] != 0)
		free(tab[i++]);
	free(tab);
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
			if (ft_strncmp(line, "##start", 7) == 0)
				scrap_start(&line, hive);
			else if (ft_strncmp(line, "##end", 5) == 0)
				scrap_end(&line, hive);
			/* else
			   scrap_info(line, hive); */
			free(line);
		}
	free_hive(hive);
	return (0);
}




















