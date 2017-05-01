#include "lem_in.h"

void	free_node(t_node *lst)
{
	if (lst != NULL)
	{
		if (lst->link != NULL)
			free_node(lst->link);
		free(lst->name);
		free(lst->via);
		free(lst);
	}
}

void	free_via(t_via *lst)
{
	if (lst != NULL)
	{
		if (lst->link != NULL)
			free_via(lst->link);
		free(lst->n1);
		free(lst->n2);
		free(lst);
	}
}

void	free_hive(t_hive *hive)
{
	free_node(hive->start);
	free_via(hive->v_lst);
	free(hive->way);
	free(hive);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		free(tab[i++]);
	free(tab);
}

void	free_all(t_hive *hv, char **tab, char *line)
{
	if (hv != NULL)
		free_hive(hv);
	if (tab != NULL)
		free_tab(tab);
	if (line != NULL)
		free(line);
}










