/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorttab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 18:57:17 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/12/15 19:01:00 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ft_sorttab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
	return (tab);
}
