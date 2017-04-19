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

int		is_node(char **tab)
{
	if (tab[0][0] == 0 ||
		tab[0][0] == 'L' ||
		!is_nb(tab[1]) ||
		!is_nb(tab[2]))
		{
			ft_printf("Error : File bad formatted\n");
			exit(1);
		}
	else
		return(1);
}

int		is_via(char **tab)
{
	if (tab[0][0] == 0 ||
		tab[0][0] == 'L' ||
		tab[1][0] == 0 ||
		tab[1][0] == 'L')
		{
			ft_printf("Error : File bad formatted\n");
			exit(1);
		}
	else
		return(1);
}
