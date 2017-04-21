#include "lem_in.h"

int		len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
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
			if (is_nb(*line))
				{
					hv->ant = ft_atoi(*line);
					free(*line);
					get_next_line(0, line);
				}
			else
				{
					ft_printf("Error : ant number bad formated\n");
					exit (1);
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
