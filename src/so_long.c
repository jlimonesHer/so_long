/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:53:30 by jlimones          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/13 15:57:32 by jlimones         ###   ########.fr       */
=======
/*   Updated: 2023/02/04 11:23:26 by jlimones         ###   ########.fr       */
>>>>>>> e397e74c1f03a57c09a84d30986a2c1e6cd51e62
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

<<<<<<< HEAD
void	leaks(void)
=======
/**
 * @brief funcion para comprobar los leaks de memoria
 * 
 */
// void	leaks(void)
// {
// 	system("leaks so_long");
// }

static	int	init_col(t_img_p *p_map)
>>>>>>> e397e74c1f03a57c09a84d30986a2c1e6cd51e62
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
<<<<<<< HEAD
	ft_save_imgs(&p_map->textures);
	p_map->map = map;
	p_map->x = position_item_x(p_map->map, 'P') * 55;
	p_map->y = position_item_y(p_map->map, 'P') * 55;
	p_map->width = (ft_width(map) * 55);
	p_map->height = (ft_height(map) * 55);
=======
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
>>>>>>> e397e74c1f03a57c09a84d30986a2c1e6cd51e62
}

int	main(int argc, char **argv)
{
	t_img_p	p_map;

<<<<<<< HEAD
	atexit(leaks);
=======
>>>>>>> e397e74c1f03a57c09a84d30986a2c1e6cd51e62
	if (argc == 2)
	{	
		ft_init_p_map(argv[1], &p_map);
		ft_generate_window(&p_map);
	}
	else
	{
		ft_printf("help: [./so_long maps/map.ber]\n");
		ft_error("Debe incluir la ruta del archivo que contine el mapa.\n");
	}
	return (0);
}
<<<<<<< HEAD
/**
 * Comentarios:
 * Hay que hacer una funcion para terminar el programa limpiamente
 * DEscomentar imagenes no creadas (img_col y img_bad)
 * Hay que hacer una funcion de errores y terminado de mapa
 */
=======
>>>>>>> e397e74c1f03a57c09a84d30986a2c1e6cd51e62
