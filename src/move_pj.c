/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:19:13 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/15 12:19:18 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Imprime la tecla
 * 
 * @param keydata 
 * @param p_map 
 * @param img 
 */
void	ft_print_key(mlx_key_data_t keydata, t_img_p *p_map, mlx_texture_t *img)
{
	ft_printf("key: %i\n", keydata.key);
	if (keydata.key == MLX_KEY_W)
		p_map->y -= 11;
	else if (keydata.key == MLX_KEY_S)
		p_map->y += 11;
	else if (keydata.key == MLX_KEY_A)
		p_map->x -= 11;
	else if (keydata.key == MLX_KEY_D)
		p_map->x += 11;
	read_and_draw_map(p_map->file, p_map->textures, p_map);
	mlx_draw_texture(p_map->img, img, p_map->x, p_map->y);
}

static void	ft_key_scp(mlx_key_data_t keydata, t_img_p *p_map)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(p_map->mlx);
}

/**
 * @brief 
 * 
 * @param p_map 
 * @param x 
 * @param y 
 * @param eje h: eje horizontal, v: eje vertical
 * @return int 
 */
static int	ft_is_wall(t_img_p *p_map, int pix_x, int pix_y, char eje)
{
	int	x;
	int	y;

	x = pix_x / PIXEL;
	y = pix_y / PIXEL;
	if (p_map->map[y][x] == '1')
		return (1);
	if (eje == 'v' && pix_x % PIXEL != 0)
	{
		if (p_map->map[y][x + 1] == '1')
			return (1);
	}
	if (eje == 'h' && pix_y % PIXEL != 0)
	{
		if (p_map->map[y + 1][x] == '1')
			return (1);
	}
	return (0);
}

/**
 * @brief Funcion para desplazar el personaje
 * 
 * @param keydata recibe la key de las teclas
 * @param param parametro vacio
 */
void	move_and_perspective(mlx_key_data_t keydata, void *param)
{
	t_img_p		*p_map;

	p_map = (t_img_p *)param;
	ft_key_scp(keydata, p_map);
	if (keydata.key == MLX_KEY_W
		&& !ft_is_wall(p_map, p_map->x, p_map->y - 11, 'v'))
		ft_print_key(keydata, p_map, p_map->textures.img_back);
	else if (keydata.key == MLX_KEY_S
		&& !ft_is_wall(p_map, p_map->x, p_map->y + PIXEL, 'v'))
		ft_print_key(keydata, p_map, p_map->textures.img_front);
	else if (keydata.key == MLX_KEY_A
		&& !ft_is_wall(p_map, p_map->x - 11, p_map->y, 'h'))
		ft_print_key(keydata, p_map, p_map->textures.img_left);
	else if (keydata.key == MLX_KEY_D
		&& !ft_is_wall(p_map, p_map->x + PIXEL, p_map->y, 'h'))
		ft_print_key(keydata, p_map, p_map->textures.img_right);
}