/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_item.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:49:10 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/21 14:59:27 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief localiza el eje y objeto pasado por parametro
 * 
 * @param p_map struck con variables inicializadas
 * @param obj objeto a localizar
 * @return int posicion  en el mapa
 */
int	position_item_y_matrix(t_img_p *p_map, char obj)
{
	int	x;
	int	y;

	y = 0;
	while (y < p_map->height && p_map->map[y][x] != obj)
	{
		x = 0;
		while (x < p_map->width && p_map->map[y][x] != obj)
			x++;
		if (p_map->map[y][x] != obj)
			y++;
	}
	if (p_map->map[y][x] == obj)
		return (y + 1);
	return (0);
}

/**
 * @brief localiza el eje x objeto pasado por parametro
 * 
 * @param p_map struck con variables inicializadas
 * @param obj objeto a localizar
 * @return int posicion x en el mapa
 */
int	position_item_x_matrix(t_img_p *p_map, char obj)
{
	int	x;
	int	y;

	if (obj == 'P')
		y = (p_map->y) / PIXEL;
	if (obj == 'C')
		y = (p_map->p_items.y_col) / PIXEL;
	if (obj == 'B')
		y = (p_map->p_items.y_bad) / PIXEL;
	if (obj == 'E')
		y = (p_map->p_items.y_door) / PIXEL;
	x = 0;
	while (x < p_map->width && p_map->map[y][x] != obj)
		x++;
	if (p_map->map[y][x] == obj)
		return (x);
	return (0);
}
