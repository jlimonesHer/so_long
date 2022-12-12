/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:53:30 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/12 19:24:12 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

typedef struct s_move
{
    mlx_image_t *img;
    mlx_texture_t *texture;
    int x;
    int y;
}   t_move;

void func(mlx_key_data_t keydata, void* param)
{
    t_move *move = (t_move *)param;
    
    // if (keydata.action != 2)
    //     return ;
    printf("KEY: %d.    MLX_KEY_W: %d\n", keydata.key, MLX_KEY_W);
    // printf("action: %d\n", keydata.action);
    // printf("modified: %d\n", keydata.modifier);
    if (keydata.key == MLX_KEY_W)
        move->y -= 10;
    if (keydata.key == MLX_KEY_S)
        move->y += 10;
    mlx_draw_texture(move->img, move->texture, move->x, move->y);
}

int main(void)
{
    t_move move;
    move.x = 200;
    move.y = 200;
    
    mlx_t *mlx = mlx_init(1000,1000,"prueba so_long", true);
    move.img = mlx_new_image(mlx, 1000, 1000);
	if (!move.img)
		printf("error");
        
    // int i = 0;
    // while(i < 900)
    // {   
    //     for (int l=0; l < 10; l++)
    //     {
    //         int j = 0;
    //         while(j < 900)
    //         {
    //             for (int k=0; k < 10; k++)
    //                 mlx_put_pixel(img, j + k, i+l, 0x00FF00FF + j*i);
    //             j += 10;
    //         }
    //     }
    //     i += 10;
    // }

    mlx_key_hook(mlx, func, &move);
    
    move.texture = mlx_load_png("/Users/jlimones/Desktop/Cursus/so_long/src/bomba.png");
    if (!move.texture)
        return (-1);
    mlx_draw_texture(move.img, move.texture, move.x, move.y);
    
    mlx_image_to_window(mlx, move.img, 0, 0);
    mlx_loop(mlx);
}