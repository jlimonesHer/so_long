/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:53:30 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/12 15:53:17 by jlimones         ###   ########.fr       */
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
void	ft_map_void(t_img_p *posit)
{
	int				x;
	int				y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_draw_texture(posit->img, posit->textures.img_flat, x, y);
			x += posit->textures.img_flat->width;
		}
		y += posit->textures.img_flat->height;
	}
}

void	leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	atexit(leaks);
	if (argc == 2)
	{	
		ft_generate_window(argv[1]);
	}
}
/**
 * Comentarios:
 * Hay que haer una funcion para terminar el programa limpiamente
 * DEscomentar imagenes no creadas (img_col y img_bad)
 * Hay que hacer una funcion de errores y terminado de mapa
 */