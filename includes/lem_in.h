/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 12:12:18 by gvandeve          #+#    #+#             */
/*   Updated: 2017/04/19 14:45:19 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <string.h>
# include <errno.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_hive	t_hive;
typedef struct s_prec	t_prec;
typedef struct s_node	t_node;
typedef struct s_via	t_via;

struct	s_hive
{
	int		ant;
	t_node	*start;
	t_node	*end;
	t_node	**way;
	t_node	*n_lst;
	t_via	*v_lst;
};

struct	s_node
{
	char	*name;
	int		ant;
	int		x;
	int		y;
	int		pnd;
	t_node	*prec;
	t_node	**via;
	t_node	*link;
};

struct	s_via
{
	char	*n1;
	char	*n2;
	t_via	*link;
};


t_node		*init_node(char *name, char *x, char *y);
t_node		*new_elem_n(char *name, char *x, char *y, t_node *nd);
void		free_hive(t_hive *hive);
void		free_node(t_node *lst);
void		free_via(t_via *lst);
void		free_tab(char **tab);
int			len(char **tab);
int			is_node(char **tab, t_hive *hv, char *line);
int			is_via(char **tab, t_hive *hv, char *line);
int			is_nb(char *nb);
void		node_proceed(char **tab, t_hive *hv, char *line);
void		via_proceed(char **tab, t_hive *hv, char *line);
void		print_lst_n(t_node *lst);
void		print_lst_v(t_via *lst);
t_via		*init_via(char *name1, char *name2);
t_via		*new_elem_v(char *name1, char *name2, t_via *via);
int			node_viable(char **tab, t_hive *hv, char *line);
int			via_viable(char **tab, t_hive *hv, char *line);
void		check_start(char **tab, t_hive *hv, char *line);
void		check_end(char **tab, t_hive *hv, char *line);
void		free_all(t_hive *hv, char **tab, char *line);
void		scrap_ant(t_hive *hv, char **line);
int			node_exist(char **name_tab, t_hive *hv);
void		enter_calc(t_hive *hv);
void		build_web(t_hive *hv);
int			count_via(t_node *nlst, t_via *vlst);
void		recur_print_lst(t_node *nlst);
void		build_way(t_hive *hv);
void		expl_via(t_node *lst, t_node **vlst, int pnd, t_node *end);
void		print_lst_p(t_node *lst);
void		format(t_hive *hv);
void		add_last(t_node *node, t_node *add);
int			llen(t_node *node);
int			lenn(t_node **node);

#endif


















