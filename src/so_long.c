/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:53:30 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/20 10:35:44 by jlimones         ###   ########.fr       */
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
void	ft_map_void(t_position posit, char *path)
{
	int				x;
	int				y;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_draw_texture(posit.img, texture, x, y);
			x += texture->width;
		}
		y += texture->height;
	}
}

/**
 * @brief Esta funcion escribe las teclas pulsadas en la terminal 
 * 
 * @param keydata El numero de la tecla utilizada
 * @param move Struct de posiciones e imagenes del escenario
 */
void	ft_print_key_and_draw(mlx_key_data_t keydata, t_position *move)
{
	ft_printf("key: %i\n", keydata.key);
	ft_map_void(*move, "./img/flat2.png");
	mlx_draw_texture(move->img, move->texture, move->x, move->y);
}

void	move_and_perspective(mlx_key_data_t keydata, void *param)
{
	t_position		*move;

	move = (t_position *)param;
	if (keydata.key == MLX_KEY_W)
	{
		move->texture = mlx_load_png("./img/back_flat.png");
		move->y -= 4;
	}
	else if (keydata.key == MLX_KEY_S)
	{
		move->texture = mlx_load_png("./img/front_flat.png");
		move->y += 4;
	}
	else if (keydata.key == MLX_KEY_A)
	{
		move->texture = mlx_load_png("./img/left_flat.png");
		move->x -= 4;
	}
	else if (keydata.key == MLX_KEY_D)
	{
		move->texture = mlx_load_png("./img/right_flat.png");
		move->x += 4;
	}
	ft_print_key_and_draw(keydata, move);
}

int	main(int argc, char **argv, char **envp)
{
	t_position	posit;

	read_map(argv[1]);
	if (argc == 2)
	{	
		posit.x = 50;
		posit.y = 50;
		posit.mlx = mlx_init(WIDTH, HEIGHT, "prueba so_long", false);
		posit.img = mlx_new_image(posit.mlx, 1000, 1000);
		ft_map_void(posit, "./img/flat2.png");
		if (!posit.img)
			ft_printf("error");
		mlx_key_hook(posit.mlx, move_and_perspective, &posit);
		posit.texture = mlx_load_png("./img/front_flat.png");
		mlx_draw_texture(posit.img, posit.texture, posit.x, posit.y);
		mlx_image_to_window(posit.mlx, posit.img, 0, 0);
		mlx_loop(posit.mlx);
	}
}
