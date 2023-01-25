/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_road.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:53:24 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/25 09:58:50 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief pinta todas las casillas accesibles con una x y asi comprobar que 
 * hay un camino posible
 * 
 * @param p_map  recibe las variables inicializadas
 * @param y recibe la posicion y del personaje
 * @param x recibe la posicion x del personaje
 */
static void	ft_print_x_map(t_img_p *p_map, int y, int x)
{
	char	c;

	c = p_map->map[y][x];
	printf("c = %c\n", p_map->map[y][x]);
	if (c == 'x')
		return ;
	if (c != '1' && c != '\0' && p_map->map[y] != 0)
	{
		p_map->map[y][x] = 'x';
		ft_print_x_map(p_map, y + 1, x);
		ft_print_x_map(p_map, y - 1, x);
		ft_print_x_map(p_map, y, x + 1);
		ft_print_x_map(p_map, y, x - 1);
	}
}

/**
 * @brief busca caracteres diferentes a 'x' y '1'
 * 
 * @param p_map recibe las variables inicializadas
 * @return int 
 */
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
