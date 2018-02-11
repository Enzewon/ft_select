#include "../includes/ft_lib.h"

static void	output_args(void)
{
	t_node	*node;
	t_out	*out;
	int		check;

	out = save_out(NULL);
	node = out->begin;
	check = 0;
	while (node)
	{
		if (node->select)
		{
			if (check == 1)
				ft_putchar(' ');
			ft_putstr(node->name);
			check = 1;
		}
		node = node->next;
	}
	if (check == 1)
		ft_putchar('\n');
}

int		exit_output(void)
{
	reset_termios();
	output_args();
	return (0);
}

int		exit_program(void)
{
	reset_termios();
	return (0);
}
