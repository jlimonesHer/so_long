/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:49:05 by jlimones          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/13 13:22:20 by jlimones         ###   ########.fr       */
=======
/*   Updated: 2023/01/13 17:56:22 by jlimones         ###   ########.fr       */
>>>>>>> 7d83d99... Empezar aqui
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_key(mlx_key_data_t keydata, t_img_p *p_map, mlx_texture_t *img)
{
<<<<<<< HEAD
	ft_printf("key: %i\n", keydata.key);
	read_and_draw_map(p_map->map, p_map->textures, p_map);
	//printf("x = %i, y = %i\n", p_map->x, p_map->y);
=======
	ft_printf("key: %in", keydata.key);
	read_and_draw_map("maps/map3.ber", p_map->textures, p_map);
>>>>>>> 7d83d99... Empezar aqui
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
	t_img_p			*p_map;

	p_map = (t_img_p *)param;
	if (keydata.key == MLX_KEY_W)
	{
		p_map->y -= 20;
		ft_print_key(keydata, p_map, p_map->textures.img_back);
	}
	else if (keydata.key == MLX_KEY_S)
	{
		p_map->y += 20;
		ft_print_key(keydata, p_map, p_map->textures.img_front);
	}
	else if (keydata.key == MLX_KEY_A)
	{
		p_map->x -= 20;
		ft_print_key(keydata, p_map, p_map->textures.img_left);
	}
	else if (keydata.key == MLX_KEY_D)
	{
		p_map->x += 20;
		ft_print_key(keydata, p_map, p_map->textures.img_right);
	}
}