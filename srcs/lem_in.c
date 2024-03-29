/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 12:16:00 by gvandeve          #+#    #+#             */
/*   Updated: 2017/05/28 21:12:14 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		scrap_info(char **line, t_hive *hv)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(*line, ' ');
	if (len(tab) == 3)
		node_proceed(tab, hv, *line);
	else
	{
		free_tab(tab);
		tab = ft_strsplit(*line, '-');
		if (len(tab) == 2)
			via_proceed(tab, hv, *line);
		else
		{
			free_all(hv, tab, NULL);
			ft_putstr_fd("Error : File bad formatted\n", 2);
			exit(1);
		}
	}
	free_tab(tab);
}

static void		scrap_start(char **line, t_hive *hv)
{
	char		**tab;
	static int	flag_start = 0;

	if (flag_start != 42)
	{
		hv->buff = new_elem_b(*line, hv->buff);
		flag_start = 42;
		free(*line);
		get_next_line(0, line);
		hv->buff = new_elem_b(*line, hv->buff);
		tab = ft_strsplit(*line, ' ');
		check_start(tab, hv, *line);
		free_tab(tab);
		free(*line);
		get_next_line(0, line);
	}
	else
	{
		free_all(hv, tab, *line);
		ft_putstr_fd("Error : Duplicate of start\n", 2);
		exit(1);
	}
}

static void		scrap_end(char **line, t_hive *hv)
{
	char		**tab;
	static int	flag_end = 0;

	if (flag_end != 42)
	{
		hv->buff = new_elem_b(*line, hv->buff);
		flag_end = 42;
		free(*line);
		get_next_line(0, line);
		hv->buff = new_elem_b(*line, hv->buff);
		tab = ft_strsplit(*line, ' ');
		check_end(tab, hv, *line);
		free_tab(tab);
		free(*line);
		get_next_line(0, line);
	}
	else
	{
		free_all(hv, tab, *line);
		ft_putstr_fd("Error : Duplicate of end\n", 2);
		exit(1);
	}
}

int				main(void)
{
	char	*line;
	t_hive	*hive;
	int		flag;

	flag = 0;
	hive = (t_hive*)ft_memalloc(sizeof(t_hive));
	while (get_next_line(0, &line) > 0)
	{
		scrap_ant(hive, &line);
		if (ft_strcmp(line, "##start") == 0)
			scrap_start(&line, hive);
		if (ft_strcmp(line, "##end") == 0)
			scrap_end(&line, hive);
		hive->buff = new_elem_b(line, hive->buff);
		if (ft_strncmp(line, "#", 1) != 0)
			scrap_info(&line, hive);
		free(line);
	}
	enter_calc(hive);
	free_hive(hive);
	return (0);
}
