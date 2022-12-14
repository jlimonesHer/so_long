/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:53:30 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/14 11:47:09 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

typedef struct s_position
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*texture;
	int				x;
	int				y;
}	t_position;

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

void	move_and_perspective(mlx_key_data_t keydata, void *param)
{
	t_position		*move;

	move = (t_position *)param;
	if (keydata.key == MLX_KEY_W)
	{
		move->texture = mlx_load_png("./img/evil_back.png");
		move->y -= 6;
	}
	else if (keydata.key == MLX_KEY_S)
	{
		move->texture = mlx_load_png("./img/evil.png");
		move->y += 6;
	}
	else if (keydata.key == MLX_KEY_A)
	{
		move->texture = mlx_load_png("./img/evil_left.png");
		move->x -= 6;
	}
	else if (keydata.key == MLX_KEY_D)
	{
		move->texture = mlx_load_png("./img/evil_right.png");
		move->x += 6;
	}
	ft_printf("key: %i\n", keydata.key);
	mlx_draw_texture(move->img, move->texture, move->x, move->y);
}
/*
void	ft_map()
{
	
}
*/

int	main(void)
{
	t_position	move;

	move.x = 50;
	move.y = 50;
	move.mlx = mlx_init(900, 900, "prueba so_long", false);
	move.img = mlx_new_image(move.mlx, 1000, 1000);
	if (!move.img)
		printf("error");
	mlx_key_hook(move.mlx, move_and_perspective, &move);
	move.texture = mlx_load_png("./img/evil.png");
	if (!move.texture)
		return (-1);
	mlx_draw_texture(move.img, move.texture, move.x, move.y);
	mlx_image_to_window(move.mlx, move.img, 0, 0);
	mlx_loop(move.mlx);
}
