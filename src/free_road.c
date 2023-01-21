/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_road.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:53:24 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/21 15:28:19 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_print_x_map(t_img_p *p_map, int y, int x)
{
	char	c;

	c = p_map->map[y][x];
	if (c == 'x')
		return ;
	if (c != '1')
	{
		p_map->map[y][x] = 'x';
		ft_print_x_map(p_map, y + 1, x);
		ft_print_x_map(p_map, y - 1, x);
		ft_print_x_map(p_map, y, x + 1);
		ft_print_x_map(p_map, y, x - 1);
	}
}

int	ft_free_road(t_img_p *p_map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_print_x_map(p_map, p_map->y / PIXEL, p_map->x / PIXEL);
	while (i < p_map->height)
	{
		j = 0;
		while (j < p_map->width)
		{
			if (p_map->map[i][j] != '1' && p_map->map[i][j] != 'x')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
