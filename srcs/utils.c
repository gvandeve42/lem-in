#include "lem_in.h"

int		len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

void	print_lst(t_node *lst)
{
	if (lst != NULL)
		{
			ft_printf("|||NODE : %10s, %10d, %10d|||\n", lst->name, lst->x, lst->y);
			print_lst(lst->link);
		}
}
