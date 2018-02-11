#include "../includes/ft_lib.h"

static t_node	*ft_nodenew(char *str)
{
	t_node		*tmp;
	struct stat	info;

	if (!(tmp = (t_node*)ft_memalloc(sizeof(t_node))))
		exit(3);
	tmp->name = ft_strdup(str);
	lstat(str, &info);
	tmp->chmod = ft_chmod(info);
	return (tmp);
}

static void		ft_nodepushback(t_node **lst, char *name)
{
	t_node	*node;

	node = *lst;
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = ft_nodenew(name);
		node->next->prev = node;
	}
	else
		*lst = ft_nodenew(name);
}

static t_out	*set_params(t_node *lst, int size)
{
	t_out	*output;

	output = (t_out*)ft_memalloc(sizeof(t_out));
	output->index = 0;
	ft_bzero(output->search, 1024);
	output->begin = lst;
	output->now = lst;
	while (lst->next)
		lst = lst->next;
	output->end = lst;
	output->no_size = 0;
	output->now->select_now = 1;
	output = save_out(output);
	ft_find_max();
	output->size = size;
	return (output);
}

static void		begin_ft_select(char **table, int size)
{
	int		i;
	t_node	*node;
	t_out	*out;

	i = -1;
	while (table[++i])
		ft_nodepushback(&node, table[i]);
	out = set_params(node, size);
	control_termios();
	catch_signals();
	take_size();
	make_term();
	delete_output();
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		begin_ft_select(argv + 1, argc - 1);
	return (0);
}
