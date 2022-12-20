/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:53:30 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/20 18:47:26 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

/**
 * @brief Esta funcion limpiara la imagen del PJ
 * 
 * @param img recibe la imagen del PJ
 */
void	clean_image(mlx_image_t *img)
{
	int	p;
	int	n_pixeles;

	n_pixeles = img->height * img->width;
	p = 0;
	while (p < n_pixeles)
		img->pixels[p++] = 0;
}

/**
 * @brief 
 * 
 * @param posit 
 * @param flat_void 
 */
void	ft_map_void(t_position *posit)
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

/**
 * @brief Esta funcion escribe las teclas pulsadas en la terminal 
 * 
 * @param keydata El numero de la tecla utilizada
 * @param move Struct de posiciones e imagenes del escenario
 */
void	ft_print_key_and_draw(mlx_key_data_t keydata, t_position *move, mlx_texture_t *img)
{
	ft_printf("key: %i\n", keydata.key);
	ft_map_void(move);
	mlx_draw_texture(move->img, img, move->x, move->y);
}

void	move_and_perspective(mlx_key_data_t keydata, void *param)
{
	t_position		*move;

	move = (t_position *)param;
	if (keydata.key == MLX_KEY_W)
	{
		move->y -= 4;
		ft_print_key_and_draw(keydata, move, move->textures.img_back);
	}
	else if (keydata.key == MLX_KEY_S)
	{
		move->y += 4;
		ft_print_key_and_draw(keydata, move, move->textures.img_front);
	}
	else if (keydata.key == MLX_KEY_A)
	{
		move->x -= 4;
		ft_print_key_and_draw(keydata, move, move->textures.img_left);
	}
	else if (keydata.key == MLX_KEY_D)
	{
		move->x += 4;
		ft_print_key_and_draw(keydata, move, move->textures.img_right);
	}
}

void	leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_position	posit;

	atexit(leaks);
	if (argc == 2)
	{	
		posit.x = 50;
		posit.y = 50;
		read_map(argv[1], posit);
		posit.mlx = mlx_init(WIDTH, HEIGHT, "prueba so_long", false);
		posit.img = mlx_new_image(posit.mlx, 1000, 1000);
		ft_save_imgs(&posit.textures);
		ft_map_void(&posit);
		if (!posit.img)
			ft_printf("error");
		mlx_key_hook(posit.mlx, move_and_perspective, &posit);
		//posit.texture = mlx_load_png("./img/front_flat.png");
		mlx_draw_texture(posit.img, posit.textures.img_front, posit.x, posit.y);
		mlx_image_to_window(posit.mlx, posit.img, 0, 0);
		mlx_loop(posit.mlx);
		ft_delete_imgs(&posit.textures);
		mlx_terminate(posit.mlx);
	}
}
