/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2023/01/12 11:49:05 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/13 13:22:20 by jlimones         ###   ########.fr       */
=======
/*   Created: 2023/01/15 12:19:13 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/24 12:44:04 by jlimones         ###   ########.fr       */
>>>>>>> e397e74c1f03a57c09a84d30986a2c1e6cd51e62
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief controla el movimiento del pj
 * 
 * @param keydata recibe la tecla pulsada
 * @param p_map recibe la struck inicializada
 * @param img recibe la imagen de fondo
 */

void	ft_print_key(mlx_key_data_t keydata, t_img_p *p_map, mlx_texture_t *img)
{
<<<<<<< HEAD
	ft_printf("key: %i\n", keydata.key);
	read_and_draw_map(p_map->map, p_map->textures, p_map);
	//printf("x = %i, y = %i\n", p_map->x, p_map->y);
=======
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
>>>>>>> e397e74c1f03a57c09a84d30986a2c1e6cd51e62
	mlx_draw_texture(p_map->img, img, p_map->x, p_map->y);
}

static void	ft_key_scp(mlx_key_data_t keydata, t_img_p *p_map)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(p_map->mlx);
}

/**
 * @brief comprueba si hay un muro para saber si el movimiento es posible
 * 
 * @param p_map la struck inicializada
 * @param pix_x recibe la posicion x del proximo movimiento
 * @param pix_y recibe la posicion y del prosimo movimiento
 * @param eje h: eje horizontal, v: eje vertical
 * @return int 
 */
static int	ft_is_wall(t_img_p *p_map, int pix_x, int pix_y, char eje)
{
<<<<<<< HEAD
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
=======
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
>>>>>>> e397e74c1f03a57c09a84d30986a2c1e6cd51e62
	}
	if (eje == 'h' && pix_y % PIXEL != 0)
	{
<<<<<<< HEAD
		p_map->x -= 20;
		ft_print_key(keydata, p_map, p_map->textures.img_left);
=======
		if (p_map->map[y + 1][x] == '1')
			return (1);
>>>>>>> e397e74c1f03a57c09a84d30986a2c1e6cd51e62
	}
	return (0);
}

/**
 * @brief Funcion para desplazar el personaje 
 * controla que no entre en la zona del enemigo si lo hace se acaba la partida
 * controla que no entre en la zona de la salida y has cogido todos los 
 * coleccionables si lo hace se acaba la partida
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
			&& p_map->open == 1) && !(p_map->x >= p_map->p_items.x_bad - INVADE
			&& p_map->x <= p_map->p_items.x_bad + INVADE
			&& p_map->y >= p_map->p_items.y_bad - INVADE
			&& p_map->y <= p_map->p_items.y_bad + INVADE))
	{
<<<<<<< HEAD
		p_map->x += 20;
		ft_print_key(keydata, p_map, p_map->textures.img_right);
=======
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
>>>>>>> e397e74c1f03a57c09a84d30986a2c1e6cd51e62
	}
}
