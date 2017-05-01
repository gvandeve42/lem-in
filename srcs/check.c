#include "lem_in.h"

int		is_nb(char *nb)
{
	while (*nb)
		{
			if (!ft_isdigit(*nb++))
				return (0);
		}
	return (1);
}

int		is_node(char **tab, t_hive *hv, char *line)
{
	if (tab[0][0] == 0 ||
		tab[0][0] == 'L' ||
		!is_nb(tab[1]) ||
		!is_nb(tab[2]))
	{
		free_all(hv, tab, line);
		ft_printf("Error : File bad formatted\n");
		exit (1);
	}
	else
		return(1);
}

int		is_via(char **tab, t_hive *hv, char *line)
{
	if (tab[0][0] == 0 ||
		tab[0][0] == 'L' ||
		tab[1][0] == 0 ||
		tab[1][0] == 'L')
	{
		free_all(hv, tab, line);
		ft_printf("Error : File bad formatted\n");
		exit (1);
	}
	else
		return(1);
}

int		via_viable(char **tab, t_hive *hv, char *line)
{
	t_via	*tmp;

	tmp = hv->v_lst;
	while (tmp != NULL)
	{
		/*if ((strcmp(tab[0], tmp->n1) == 0 && strcmp(tab[1], tmp->n2) == 0) ||
			(strcmp(tab[1], tmp->n1) == 0 && strcmp(tab[0], tmp->n2) == 0) ||
			strcmp(tab[1], tab[0]) == 0)
		{
			free_all(hv, tab, line);
			ft_printf("Error : Duplicate of via name or position\n");
			exit (1);
			}*/
		tmp = tmp->link;
	}
	return (1);
}

int		node_viable(char **tab, t_hive *hv, char *line)
{
	t_node	*tmp;

	tmp = hv->n_lst;
	while (tmp != NULL)
	{
		if (strcmp(tmp->name, tab[0]) == 0 ||
			(tmp->x == ft_atoi(tab[1]) && tmp->y == ft_atoi(tab[2])))
		{
			free_all(hv, tab, line);
			ft_printf("Error : Duplicate of node name or position\n");
			exit (1);
		}
		tmp = tmp->link;
	}
	return (1);
}




















