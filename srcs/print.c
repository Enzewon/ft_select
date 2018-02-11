#include "../includes/ft_lib.h"

static void	set_settings(t_node *tmp)
{
	if (tmp->select)
		termcap_do("so");
	if (tmp->select_now)
		termcap_do("us");
}

static void	unset_settings(t_node *tmp)
{
	if (tmp->select)
		termcap_do("se");
	if (tmp->select_now)
		termcap_do("ue");
}

static int	ft_print_filename_color2(t_node *e)
{
	if (e->chmod[0] == 'l')
		ft_fprintf(2, "{#magenta}%s{#eoc}", e->name);
	else if (e->chmod[0] == 's')
		ft_fprintf(2, "{#green}%s{#eoc}", e->name);
	else if (e->chmod[0] == 'p')
		ft_fprintf(2, "{#brown}%s{#eoc}", e->name);
	else if (e->chmod[0] == 'c')
		ft_fprintf(2, "\e[48;5;3m{#blue}%s{#eoc}\e[0m", e->name);
	else if (e->chmod[0] == 'b')
		ft_fprintf(2, "\e[48;5;6m{#blue}%s{#eoc}\e[0m", e->name);
	else if (e->chmod[3] == 's' || (e->chmod[3] == 'S' &&
		((e->chmod[6] == 'x' || e->chmod[6] == 's') || (e->chmod[9] == 't' ||
			e->chmod[9] == 'x'))))
		ft_fprintf(2, "\e[48;5;1m{#black}%s{#eoc}\e[0m", e->name);
	else if (e->chmod[6] == 's' || (e->chmod[6] == 'S' &&
		(e->chmod[3] == 'x' || (e->chmod[9] == 't' || e->chmod[9] == 'x'))))
		ft_fprintf(2, "\e[48;5;6m{#black}%s{#eoc}\e[0m", e->name);
	else if (e->chmod[3] == 'x' || e->chmod[6] == 'x' ||
		e->chmod[9] == 'x' || e->chmod[9] == 't')
		ft_fprintf(2, "{#red}%s{#eoc}", e->name);
	else
		return (0);
	return (1);
}

static void	ft_print_filename_color(t_node *elem)
{
	if (elem->chmod[0] == 'd' && ft_check_rights(elem->chmod) == 0)
		ft_fprintf(2, "{#blue}%s{#eoc}", elem->name);
	else if (elem->chmod[0] == 'd' && ft_check_rights(elem->chmod) == 1 &&
		elem->chmod[9] != 't' && elem->chmod[9] != 'T')
		ft_fprintf(2, "\e[48;5;3m{#black}%s{#eoc}\e[0m", elem->name);
	else if (elem->chmod[0] == 'd' && ft_check_rights(elem->chmod) == 1 &&
		(elem->chmod[9] == 't' || elem->chmod[9] == 'T'))
		ft_fprintf(2, "\e[48;5;2m{#black}%s{#eoc}\e[0m", elem->name);
	else if (ft_print_filename_color2(elem) == 1)
		return ;
	else
		ft_fprintf(2, "%s", elem->name);
}

void		print_arg(int cols, t_node *tmp)
{
	t_out	*out;
	int		current_size;

	out = save_out(NULL);
	tmp->select_now == 1 ? ft_fprintf(2,
		" {#bold}{#yellow}>>{#eoc} ") : ft_fprintf(2, "   ");
	set_settings(tmp);
	ft_print_filename_color(tmp);
	unset_settings(tmp);
	current_size = (cols * (out->max));
	if (current_size + out->max > out->width)
	{
		ft_putchar(' ');
		return ;
	}
	if (tmp->select_now)
		ft_place_shift_fd(out->max - ft_strlen(tmp->name) - 4, 2);
	else
		ft_place_shift_fd(out->max - ft_strlen(tmp->name) - 3, 2);
}
