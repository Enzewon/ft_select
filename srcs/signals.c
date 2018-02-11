#include "../includes/ft_lib.h"

t_out		*save_out(t_out *output)
{
	static t_out	*save;

	if (output)
		save = output;
	return (save);
}

static void	pause_process(void)
{
	reset_termios();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

static void	restore_process(void)
{
	control_termios();
	catch_signals();
	print_list();
}

void		handler(int sig)
{
	if (sig == SIGTSTP)
		pause_process();
	else if (sig == SIGCONT)
		restore_process();
	else if (sig == SIGTERM || sig == SIGABRT || sig == SIGINT ||
		sig == SIGSTOP || sig == SIGKILL || sig == SIGQUIT)
		exit_program();
	else if (sig == SIGWINCH)
	{
		take_size();
		print_list();
	}
}

void		catch_signals(void)
{
	signal(SIGWINCH, handler);
	signal(SIGTERM, handler);
	signal(SIGABRT, handler);
	signal(SIGINT, handler);
	signal(SIGSTOP, handler);
	signal(SIGCONT, handler);
	signal(SIGTSTP, handler);
	signal(SIGKILL, handler);
	signal(SIGQUIT, handler);
}
