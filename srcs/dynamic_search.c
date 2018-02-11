/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 11:28:13 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/10/09 11:28:14 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

static void	find_elem(void)
{
	t_node	*tmp;
	t_out	*out;

	out = save_out(NULL);
	tmp = out->begin;
	while (tmp)
	{
		if (ft_strstr(tmp->name, out->search) != NULL)
			break ;
		tmp = tmp->next;
	}
	if (tmp)
	{
		out->now->select_now ^= 1;
		go_to_elem();
		out->now = tmp;
		out->now->select_now ^= 1;
		go_to_elem();
	}
}

static void	add_char(char buf)
{
	t_out	*out;

	out = save_out(NULL);
	out->search[out->index] = buf;
	out->index++;
}

void	dynamic_search(char key)
{
	t_out	*out;

	out = save_out(NULL);
	add_char(key);
	find_elem();
}
