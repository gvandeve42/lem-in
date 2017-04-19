#include "lem_in.h"

void	free_node(t_node *lst)
{
	if (lst->link != NULL)
		free_node(lst->link);
	free(lst->name);
	free(lst);
}

void	free_hive(t_hive *hive)
{
	free_node(hive->start);
	free_node(hive->end);
	free_node(hive->lst);
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
