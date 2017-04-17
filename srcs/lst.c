#include "lem_in.h"

t_node	*new_elem(char *name, char *x, char *y, t_node *nd)
{
	t_node	*anchor;

	anchor = nd;
	if (nd == NULL)
		{
			nd = init_node(name, x, y);
			return (nd);
		}
	else
		{
			while (nd->link != NULL)
				nd = nd->link;
			nd->link = init_node(name, x, y);
		}
	return (anchor);
}
