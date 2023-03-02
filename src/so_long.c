/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:53:30 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/13 15:57:32 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	clean_image(mlx_image_t *img)
// {
// 	int	p;
// 	int	n_pixeles;

// 	n_pixeles = img->height * img->width;
// 	p = 0;
// 	while (p < n_pixeles)
// 		img->pixels[p++] = 0;
// }

#include "so_long.h"

void	leaks(void)
{
	system("leaks so_long");
}

void	ft_init_p_map(char *map, t_img_p *p_map)
{
	ft_save_imgs(&p_map->textures);
	p_map->map = map;
	p_map->x = position_item_x(p_map->map, 'P') * 55;
	p_map->y = position_item_y(p_map->map, 'P') * 55;
	p_map->width = (ft_width(map) * 55);
	p_map->height = (ft_height(map) * 55);
}

int	main(int argc, char **argv)
{
	t_img_p	p_map;

	atexit(leaks);
	if (argc == 2)
	{	
		ft_init_p_map(argv[1], &p_map);
		ft_generate_window(&p_map);
	}
}
/**
 * Comentarios:
 * Hay que hacer una funcion para terminar el programa limpiamente
 * DEscomentar imagenes no creadas (img_col y img_bad)
 * Hay que hacer una funcion de errores y terminado de mapa
 */