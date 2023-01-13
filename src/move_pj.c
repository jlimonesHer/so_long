/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:49:05 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/13 17:56:22 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_key(mlx_key_data_t keydata, t_img_p *p_map, mlx_texture_t *img)
{
	ft_printf("key: %in", keydata.key);
	read_and_draw_map("maps/map3.ber", p_map->textures, p_map);
	mlx_draw_texture(p_map->img, img, p_map->x, p_map->y);
}

/**
 * @brief Funcion para desplazar el personaje
 * 
 * @param keydata recibe la key de las teclas
 * @param param parametro vacio
 */
void	move_and_perspective(mlx_key_data_t keydata, void *param)
{
	t_img_p		*move;

	move = (t_img_p *)param;
	if (keydata.key == MLX_KEY_W)
	{
		move->y -= 4;
		ft_print_key(keydata, move, move->textures.img_back);
	}
	else if (keydata.key == MLX_KEY_S)
	{
		move->y += 4;
		ft_print_key(keydata, move, move->textures.img_front);
	}
	else if (keydata.key == MLX_KEY_A)
	{
		move->x -= 4;
		ft_print_key(keydata, move, move->textures.img_left);
	}
	else if (keydata.key == MLX_KEY_D)
	{
		move->x += 4;
		ft_print_key(keydata, move, move->textures.img_right);
	}
}