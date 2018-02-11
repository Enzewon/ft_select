#include "../includes/ft_lib.h"

static int	termcap_putchar(int c)
{
	write(2, &c, 1);
	return (0);
}

int			termcap_do(char *cmd)
{
	char	*tmp;

	if ((tmp = tgetstr(cmd, NULL)) == NULL)
		return (1);
	tputs(tmp, 0, termcap_putchar);
	return (0);
}

int			termcap_goto(char *cmd, int col, int row)
{
	char	*tmp;

	if ((tmp = tgetstr(cmd, NULL)) == NULL)
		return (1);
	tmp = tgoto(tmp, col, row);
	tputs(tmp, 0, termcap_putchar);
	return (0);
}
