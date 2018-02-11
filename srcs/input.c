#include "../includes/ft_lib.h"

int		go_up(void)
{
	t_out	*out;

	out = save_out(NULL);
	if (!out->no_size)
	{
		out->now->select_now ^= 1;
		go_to_elem();
		if (!out->now->prev)
			out->now = out->end;
		else
			out->now = out->now->prev;
		out->now->select_now ^= 1;
		go_to_elem();
	}
	return (1);
}

int		go_down(void)
{
	t_out	*out;

	out = save_out(NULL);
	if (!out->no_size)
	{
		out->now->select_now ^= 1;
		go_to_elem();
		if (!out->now->next)
			out->now = out->begin;
		else
			out->now = out->now->next;
		out->now->select_now ^= 1;
		go_to_elem();
	}
	return (1);
}

static void	reset_search(void)
{
	t_out	*out;

	out = save_out(NULL);
	if (out->search[0])
	{
		ft_bzero(out->search, ft_strlen(out->search) + 1);
		out->index = 0;
	}
}

static int	track_key(long key)
{
	int		i;
	t_keys	*actions;

	i = -1;
	actions = get_actions();
	while (++i < 9)
	{
		if (actions[i].value == key)
		{
			reset_search();
			return (actions[i].function());
		}
	}
	if (ft_isprint(key) || key == 127)
		dynamic_search(key);
	else
		reset_search();
	return (1);
}

void		make_term(void)
{
	long	key;

	print_list();
	while ((key = 0) || read(0, &key, sizeof(long)) != -1)
	{
		if (!track_key(key))
			return ;
	}
}
