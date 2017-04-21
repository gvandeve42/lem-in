/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 12:16:00 by gvandeve          #+#    #+#             */
/*   Updated: 2017/04/19 14:46:17 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	scrap_info(char **line, t_hive *hv)
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
				ft_printf("Error : File bad formatted\n");
				exit(1);
			}
		}
	free_tab(tab);
}

static void	scrap_start(char **line, t_hive *hv)
{
	char		**tab;
	static int	flag;

	if (flag != 42)
	{
		flag = 42;
		free(*line);
		get_next_line(0, line);
		tab = ft_strsplit(*line, ' ');
		check_start(tab, hv, *line);
		free_tab(tab);
		free(*line);
		get_next_line(0, line);
	}
	else
	{
		free_all(hv, tab, *line);
		ft_printf("Error : Duplicate of start\n");
		exit (1);
	}
}

static void	scrap_end(char **line, t_hive *hv)
{
	char		**tab;
	static int	flag;

	if (flag != 42)
	{
		flag = 42;
		free(*line);
		get_next_line(0, line);
		tab = ft_strsplit(*line, ' ');
		check_end(tab, hv, *line);
		free_tab(tab);
		free(*line);
		get_next_line(0, line);
	}
	else
	{
		free_all(hv, tab, *line);
		ft_printf("Error : Duplicate of end\n");
		exit (1);
	}
}

int		main(void)
{
	char	*line;
	t_hive	*hive;
	int		flag;

	flag = 0;
	hive = (t_hive*)ft_memalloc(sizeof(t_hive));
	while (get_next_line(0, &line))
		{
			scrap_ant(hive, &line);
			if (ft_strcmp(line, "##start") == 0)
				scrap_start(&line, hive);
			if (ft_strcmp(line, "##end") == 0)
				scrap_end(&line, hive);
			if (ft_strncmp(line, "#", 1) != 0)
				scrap_info(&line, hive);
			free(line);
		}
	enter_calc(hive);
	//print_lst_n(hive->start);
	//print_lst_v(hive->v_lst);
	//print_lst_n(hive->n_lst);
	recur_print_lst(hive->start);
	free_hive(hive);
	return (0);
}




















