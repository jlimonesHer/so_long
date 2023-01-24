/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:19:13 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/24 10:56:28 by jlimones         ###   ########.fr       */
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
	char	*str;

	str = ft_itoa(p_map->count);
	if (p_map->str_img)
		mlx_delete_image(p_map->mlx, p_map->str_img);
	p_map->str_img = mlx_put_string(p_map->mlx, str, PIXEL, PIXEL);
	free(str);
	if (keydata.action != 0)
		ft_printf("Step: %d\n", p_map->count++);
	if (keydata.key == MLX_KEY_W && keydata.action != 0)
		p_map->y -= MOVE;
	else if (keydata.key == MLX_KEY_S && keydata.action != 0)
		p_map->y += MOVE;
	else if (keydata.key == MLX_KEY_A && keydata.action != 0)
		p_map->x -= MOVE;
	else if (keydata.key == MLX_KEY_D && keydata.action != 0)
		p_map->x += MOVE;
	read_and_draw_map(p_map->file, p_map->textures, p_map);
	ft_draw_items(p_map);
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
void	move_and_perspective_p(mlx_key_data_t keydata, void *param)
{
	t_img_p		*p_map;

	p_map = (t_img_p *)param;
	ft_key_scp(keydata, p_map);
	if (!(p_map->x == p_map->p_items.x_door && p_map->y == p_map->p_items.y_door
			&& p_map->open == 1) && !(p_map->x >= p_map->p_items.x_bad - 25
			&& p_map->x <= p_map->p_items.x_bad + 25
			&& p_map->y >= p_map->p_items.y_bad - 25
			&& p_map->y <= p_map->p_items.y_bad + 25))
	{
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
}
