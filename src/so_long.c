/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:53:30 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/13 16:42:38 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

typedef struct s_position
{
    mlx_image_t *img;
    mlx_texture_t *texture;
    int x;
    int y;
}   t_position;

void    

void move_and_perspective(mlx_key_data_t keydata, void* param)
{
    t_position *move = (t_position *)param;
    int distance;
    
    distance = 6;
    if (keydata.key == MLX_KEY_W)
        {
            move->texture = mlx_load_png("/Users/jlimones/Desktop/Cursus/so_long/img/evil_back.png");
            move->y -= distance;
        }
    else if (keydata.key == MLX_KEY_S)
        {
            move->texture = mlx_load_png("/Users/jlimones/Desktop/Cursus/so_long/img/evil.png");
            move->y += distance;
        }
    else if (keydata.key == MLX_KEY_A)
        {
            move->texture = mlx_load_png("/Users/jlimones/Desktop/Cursus/so_long/img/evil_left.png");
            move->x -= distance;
        }
    else if (keydata.key == MLX_KEY_D)
        {
            move->texture = mlx_load_png("/Users/jlimones/Desktop/Cursus/so_long/img/evil_right.png");
            move->x += distance;
        }
    mlx_draw_texture(move->img, move->texture, move->x, move->y);
}

int main(void)
{
    t_position move;
    move.x = 50;
    move.y = 50;
    
    mlx_t *mlx = mlx_init(1000,1000,"prueba so_long", true);
    move.img = mlx_new_image(mlx, 1000, 1000);
	if (!move.img)
		printf("error");

    mlx_key_hook(mlx, move_and_perspective, &move);
    
    move.texture = mlx_load_png("/Users/jlimones/Desktop/Cursus/so_long/img/evil.png");
    if (!move.texture)
        return (-1);
    mlx_draw_texture(move.img, move.texture, move.x, move.y);
    
    mlx_image_to_window(mlx, move.img, 0, 0);
    mlx_loop(mlx);
}