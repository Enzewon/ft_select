/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 18:32:06 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/05/02 18:32:07 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

# include <sys/wait.h>
# include <signal.h>
# include <term.h>
# include <termios.h>
# include "ft_select_structs.h"
# include "../libft/includes/libft.h"

# define KEY_BACKSPACE		127
# define KEY_DEL			2117294875
# define KEY_LEFT 			4479771
# define KEY_RIGHT 			4414235
# define KEY_UP 			4283163
# define KEY_DOWN			4348699
# define KEY_ESC			27
# define KEY_SPACE			32
# define KEY_ENTER			10

t_out	*save_out(t_out *output);
void	delete_output(void);
t_node	*take_node_num(int num);
int		termcap_do(char *cmd);
int		termcap_goto(char *cmd, int col, int row);
int		take_size(void);
void	print_arg(int cols, t_node *tmp);
int		go_up(void);
void	dynamic_search(char key);
char	*ft_chmod(struct stat info);
void	ft_node_del(t_node *node);
int		exit_output(void);
t_keys	*get_actions(void);
void	go_to_elem(void);
void	print_arg(int cols, t_node *tmp);
int		ft_check_rights(char *str);
int		go_down(void);
void	ft_find_max(void);
int		exit_program(void);
void	catch_signals(void);
void	handler(int sig);
void	make_term(void);
void	control_termios(void);
void	reset_termios(void);
void	print_list(void);

#endif
