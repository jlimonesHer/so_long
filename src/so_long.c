/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:53:30 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/13 17:05:09 by jlimones         ###   ########.fr       */
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

/**
 * @brief 
 * 
 * @param posit 
 * @param flat_void 
 */
// void	ft_map_void(t_img_p *posit)
// {
// 	int				x;
// 	int				y;

// 	y = 0;
// 	while (y < HEIGHT)
// 	{
// 		x = 0;
// 		while (x < WIDTH)
// 		{
// 			mlx_draw_texture(posit->img, posit->textures.img_flat, x, y);
// 			x += posit->textures.img_flat->width;
// 		}
// 		y += posit->textures.img_flat->height;
// 	}
// }

void	leaks(void)
{
	system("leaks so_long");
}

void	ft_init_p_map(char *map, t_img_p *p_map)
{
	p_map->height = 55 * ft_lenght_y(map);
	p_map->width = 55 * ft_lenght_x(map);
}

int	main(int argc, char **argv)
{
	atexit(leaks);
	if (argc == 2)
	{	
		t_img_p	p_map;

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