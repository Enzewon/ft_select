#include "../includes/ft_lib.h"

void	ft_node_del(t_node *node)
{
	t_out	*out;

	out = save_out(NULL);
	if (node)
	{
		if (node->prev)
			node->prev->next = node->next;
		if (node->next)
			node->next->prev = node->prev;
		if (!node->prev)
			out->begin = node->next;
		if (!node->next)
			out->end = node->prev;
		if (node->name)
			ft_strdel(&node->name);
		if (node->chmod)
			ft_strdel(&node->chmod);
		free(node);
	}
}

static void	del_nodes(void)
{
	t_node	*tmp;
	t_out	*out;

	out = save_out(NULL);
	tmp = out->begin;
	while (tmp)
	{
		ft_node_del(tmp);
		tmp = tmp->next;
	}
}

void	delete_output(void)
{
	t_out	*out;

	out = save_out(NULL);
	del_nodes();
	free(out);
}
