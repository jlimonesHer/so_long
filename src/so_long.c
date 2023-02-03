/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:53:30 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/03 19:51:42 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief funcion para comprobar los leaks de memoria
 * 
 */
// void	leaks(void)
// {
// 	system("leaks so_long");
// }

static	int	init_col(t_img_p *p_map)
{
	int	y;
	int	x;
	int	c;

	y = -1;
	x = -1;
	c = -1;
	p_map->p_items.size_cols = ft_check_items(p_map, 0, 0, 0);
	p_map->p_items.cols = malloc(sizeof(t_col_p) * p_map->p_items.size_cols);
	if (!p_map->p_items.cols)
		return (0);
	while (p_map->height > ++y)
	{
		x = -1;
		while (p_map->map[y][++x])
		{
			if (p_map->map[y][x] == 'C')
			{
				p_map->p_items.cols[++c].visib = 1;
				p_map->p_items.cols[c].x = x;
				p_map->p_items.cols[c].y = y;
			}
		}
	}
	return (0);
}

/**
 * @brief asigna los valores a la struck inicial
 * 
 * @param file recibe el mapa.ber
 * @param p_map recibe la struc inicial
 */
void	ft_init_p_map(char *file, t_img_p *p_map)
{
	p_map->count = 0;
	p_map->file = file;
	p_map->height = ft_lenght_y(file);
	p_map->width = ft_lenght_x(file);
	ft_read_map(file, p_map);
	p_map->y = position_item_y_matrix(p_map, 'P') * PIXEL - PIXEL;
	p_map->x = position_item_x_matrix(p_map, 'P') * PIXEL;
	if (!ft_free_road(p_map))
	{
		ft_delete_map(p_map);
		ft_error("El mapa no tiene salida o hay un objeto mal colocado.\n");
	}
	ft_delete_map(p_map);
	ft_read_map(file, p_map);
	p_map->p_items.y_bad = (position_item_y_matrix(p_map, 'B') * PIXEL) - PIXEL;
	p_map->p_items.x_bad = position_item_x_matrix(p_map, 'B') * PIXEL;
	p_map->p_items.y_door = position_item_y_matrix(p_map, 'E') * PIXEL - PIXEL;
	p_map->p_items.x_door = position_item_x_matrix(p_map, 'E') * PIXEL;
	init_col(p_map);
	p_map->open = 0;
	p_map->str_img = 0;
}

int	main(int argc, char **argv)
{
	t_img_p	p_map;

	if (argc == 2)
	{	
		ft_init_p_map(argv[1], &p_map);
		ft_generate_window(argv[1], &p_map);
	}
	return (0);
}
