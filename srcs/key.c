/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 11:18:28 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/10/09 11:18:30 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

static int	go_left(void)
{
	t_node	*tmp;
	t_node	*new;
	t_out	*out;
	int		i;
	int		cols;

	out = save_out(NULL);
	cols = out->size / out->height + 1;
	if (cols != 1 && out->size % out->height == 0)
		cols--;
	if (cols != 1 && !out->no_size)
	{
		tmp = out->begin;
		i = 0;
		while (!ft_strequ(tmp->name, out->now->name) && (++i))
			tmp = tmp->next;
		new = take_node_num(i - out->height);
		if (!new)
			return (1);
		out->now->select_now ^= 1;
		go_to_elem();
		out->now = new;
		out->now->select_now ^= 1;
		go_to_elem();
	}
	return (1);
}

static int	go_right(void)
{
	t_node	*tmp;
	t_node	*new;
	t_out	*out;
	int		i;
	int		cols;

	out = save_out(NULL);
	cols = out->size / out->height + 1;
	if (cols != 1 && out->size % out->height == 0)
		cols--;
	if (cols != 1 && !out->no_size)
	{
		tmp = out->begin;
		i = 0;
		while (!ft_strequ(tmp->name, out->now->name) && (++i))
			tmp = tmp->next;
		new = take_node_num(i + out->height);
		if (!new)
			return (1);
		out->now->select_now ^= 1;
		go_to_elem();
		out->now = new;
		out->now->select_now ^= 1;
		go_to_elem();
	}
	return (1);
}

static int	select_arg(void)
{
	t_out	*out;

	out = save_out(NULL);
	if (!out->no_size)
	{
		out->now->select ^= 1;
		go_down();
		// print_list();
	}
	return (1);
}

static int	delete_arg(void)
{
	t_node	*tmp;
	t_out	*out;

	out = save_out(NULL);
	if (!out->no_size)
	{
		tmp = out->now;
		if (out->now->prev)
			go_up();
		else
			go_down();
		ft_node_del(tmp);
		out->size--;
		if (!out->begin)
			exit_program();
		ft_find_max();
		print_list();
	}
	return (1);
}

t_keys		*get_actions(void)
{
	static t_keys	actions[9] = {
	{go_up, KEY_UP},
	{go_down, KEY_DOWN},
	{go_left, KEY_LEFT},
	{go_right, KEY_RIGHT},
	{select_arg, KEY_SPACE},
	{delete_arg, KEY_BACKSPACE},
	{delete_arg, KEY_DEL},
	{exit_program, KEY_ESC},
	{exit_output, KEY_ENTER},
	};
	return (actions);
}
