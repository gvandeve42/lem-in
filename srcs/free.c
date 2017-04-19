#include "lem_in.h"

void	free_node(t_node *lst)
{
	if (lst != NULL)
	{
		if (lst->link != NULL)
			free_node(lst->link);
		free(lst->name);
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
	free_node(hive->end);
	free_node(hive->n_lst);
	free_via(hive->v_lst);
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
	free_hive(hv);
	free_tab(tab);
	free(line);
}










