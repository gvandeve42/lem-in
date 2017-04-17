/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 12:12:18 by gvandeve          #+#    #+#             */
/*   Updated: 2017/04/15 12:15:07 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_hive	t_hive;
typedef struct s_prec	t_prec;
typedef struct s_node	t_node;

struct	s_hive
{
	t_node	*start;
	t_node	*end;
	t_node	*lst;
};

struct	s_prec
{
	char	*name;
	int		weigth;
};

struct	s_node
{
	char	*name;
	int		x;
	int		y;
	t_prec	*prec;
	t_node	**prev;
	t_node	**next;
	t_node	*link;
};

t_node		*init_node(char *name, char *x, char *y);
t_node		*new_elem(char *name, char *x, char *y, t_node *nd);
void		*free_hive(t_hive *hive);

#endif
