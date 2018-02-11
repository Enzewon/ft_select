/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 11:19:36 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/10/09 11:19:37 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

static int	take_num_node(t_node *need)
{
	t_node	*tmp;
	t_out	*out;
	int		i;

	out = save_out(NULL);
	tmp = out->begin;
	i = 0;
	while (tmp && tmp != need)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void		go_to_elem(void)
{
	t_out	*out;
	int		index;

	out = save_out(NULL);
	index = take_num_node(out->now);
	termcap_goto("cm", (index / out->height) * out->max, index % out->height);
	print_arg((index / out->height) * out->max, out->now);
}
