#include "../includes/ft_lib.h"

t_node		*take_node_num(int num)
{
	t_node	*tmp;
	t_out	*out;

	out = save_out(NULL);
	tmp = NULL;
	if (num < out->size)
	{
		tmp = out->begin;
		while (tmp && num)
		{
			tmp = tmp->next;
			num--;
		}
		if (num > 0)
			return (NULL);
	}
	return (tmp);
}

static int	fit_screen(int cols, int size)
{
	int		current_size;
	t_out	*out;

	out = save_out(NULL);
	current_size = (cols * (out->max));
	if (current_size + size + 4 <= out->width)
		return (1);
	return (0);
}

static void	print_args(int row, int cols, t_out *out)
{
	t_node	*tmp;

	while (row < out->height && row <= out->size)
	{
		termcap_goto("cm", 0, row);
		termcap_do("ce");
		cols = 0;
		while (out->no_size == 0 &&
			(tmp = take_node_num((out->height * cols) + row)))
		{
			if (fit_screen(cols, ft_strlen(tmp->name)))
				print_arg(cols, tmp);
			else
			{
				out->no_size = 1;
				termcap_do("cl");
				ft_fprintf(2, "No space\n");
			}
			cols++;
		}
		row++;
	}
}

void		print_list(void)
{
	t_out	*out;

	out = save_out(NULL);
	out->no_size = 0;
	print_args(0, 0, out);
}
