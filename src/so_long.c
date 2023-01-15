/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:53:30 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/15 12:46:51 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system("leaks so_long");
}

void	ft_init_p_map(char *file, t_img_p *p_map)
{
	p_map->file = file;
	p_map->y = position_item_y(file, 'P') * PIXEL - PIXEL;
	p_map->x = position_item_x(file, 'P') * PIXEL;
	p_map->height = ft_lenght_y(file);
	p_map->width = ft_lenght_x(file);
	ft_read_map(file, p_map);
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