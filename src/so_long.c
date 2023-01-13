/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:53:30 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/13 18:36:35 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system("leaks so_long");
}

void	ft_init_p_map(char *map, t_img_p *p_map)
{
	p_map->map = map;
	p_map->bool_start = 1;
	p_map->y = position_item_y(map, 'P') * 55 - 55;
	p_map->x = position_item_x(map, 'P') * 55;
	//printf("x : %i, y: %i\n", p_map->x , p_map->y);
	p_map->height = 55 * ft_lenght_y(map);
	p_map->width = 55 * ft_lenght_x(map);
}

int	main(int argc, char **argv)
{
	t_img_p	p_map;

	atexit(leaks);
	if (argc == 2)
	{	
		ft_init_p_map(argv[1], &p_map);
		ft_generate_window(argv[1], &p_map);
	}
}
/**
 * Comentarios:
 * Hay que haer una funcion para terminar el programa limpiamente
 * DEscomentar imagenes no creadas (img_col y img_bad)
 * Hay que hacer una funcion de errores y terminado de mapa
 */