#include "lem_in.h"

t_node	*init_node(char *name, char *x, char *y)
{
	t_node	*new_node;

	new_node = (t_node*)ft_memalloc(sizeof(t_node));
	new_node->name = ft_strdup(name);
	new_node->x = (ft_atoi(x));
	new_node->y = (ft_atoi(y));
	new_node->pnd = ULONG_MAX;
	return (new_node);
}

t_via	*init_via(char *name1, char *name2)
{
	t_via	*new_via;

	new_via = (t_via*)ft_memalloc(sizeof(t_via));
	new_via->n1 = ft_strdup(name1);
	new_via->n2 = ft_strdup(name2);
	return (new_via);
}

t_hive	*init_hive(void)
{
	t_hive	*hive;

	hive = (t_hive*)ft_memalloc(sizeof(t_hive));
	return (hive);
}












