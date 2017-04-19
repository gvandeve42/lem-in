#include "lem_in.h"

t_node	*new_elem_n(char *name, char *x, char *y, t_node *nd)
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

t_via	*new_elem_v(char *name1, char *name2, t_via *via)
{
	t_via	*anchor;

	anchor = via;
	if (via == NULL)
		{
			via = init_via(name1, name2);
			return (via);
		}
	else
		{
			while (via->link != NULL)
				via = via->link;
			via->link = init_via(name1, name2);
		}
	return (anchor);
}



















