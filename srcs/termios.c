#include "../includes/ft_lib.h"

void		ft_find_max(void)
{
	int		max;
	int		size;
	t_node	*tmp;
	t_out	*out;

	max = 0;
	out = save_out(NULL);
	tmp = out->begin;
	while (tmp)
	{
		if ((size = ft_strlen(tmp->name)) > max)
			max = size;
		tmp = tmp->next;
	}
	out->max = max + 5;
}

static void	getentry(char *tty)
{
	int		res;
	char	buf[1024];

	if ((res = tgetent(buf, tty)) < 1)
	{
		if (res < 0)
			ft_fprintf(2, "Error: Could not access the termcap data base.\n");
		else if (res == 0)
			ft_fprintf(2, "Error: Terminal type `%s' is not defined.\n",
				tty);
		exit(0);
	}
}

int			take_size(void)
{
	t_out	*out;

	out = save_out(NULL);
	if (!(out->term_name = getenv("TERM")))
	{
		ft_fprintf(2, "Error: Specify a terminal type with ");
		ft_fprintf(2, "`setenv TERM <yourtype>`.\n");
		exit(0);
	}
	getentry(out->term_name);
	if (out->width != tgetnum("co") ||
		out->height != tgetnum("li"))
	{
		out->width = tgetnum("co");
		out->height = tgetnum("li");
		return (1);
	}
	return (0);
}

void	control_termios(void)
{
	t_out	*out;

	out = save_out(NULL);
	if (!(out->term_name = getenv("TERM")))
	{
		ft_fprintf(2, "Error: Specify a terminal type with ");
		ft_fprintf(2, "`setenv TERM <yourtype>`.\n");
		exit(1);
	}
	getentry(out->term_name);
	tcgetattr(STDERR_FILENO, &out->term_backup);
	tcgetattr(STDERR_FILENO, &out->term);
	out->term.c_lflag &= ~ECHO & ~ICANON;
	out->term.c_cc[VMIN] = 1;
	out->term.c_cc[VTIME] = 0;
	tcsetattr(STDERR_FILENO, TCSANOW, &out->term);
	termcap_do("os");
	termcap_do("vi");
	termcap_do("ti");
}

void	reset_termios(void)
{
	t_out	*out;

	out = save_out(NULL);
	termcap_do("te");
	termcap_do("ve");
	tcsetattr(STDERR_FILENO, TCSANOW, &out->term_backup);
}
