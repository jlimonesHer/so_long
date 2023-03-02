/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_delete_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:01:06 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/03 08:29:57 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief comprueba que no haya errores en la carga de imagenes
 * 
 * @param img recibe las imagenes
 */
static	void	ft_error_img(t_img_sprite *img)
{
	if (!img->img_front || !img->img_back || !img->img_left || !img->img_right
		|| !img->img_flat || !img->img_close_door || !img->img_open_door
		|| !img->img_wall || !img->img_col || !img->img_bad)
		ft_error("Falla al cargar una imagen\n");
}

/**
 * @brief Funcion para guardar las imagenes en una struck
 * 
 * @param img recibe las imagenes
 */
void	ft_save_imgs(t_img_sprite *img)
{
	img->img_front = mlx_load_png("./img/evil_front.png");
	img->img_back = mlx_load_png("./img/evil_back.png");
	img->img_left = mlx_load_png("./img/evil_left.png");
	img->img_right = mlx_load_png("./img/evil_right.png");
	img->img_flat = mlx_load_png("./img/flat_new.png");
	img->img_close_door = mlx_load_png("./img/close_door.png");
	img->img_open_door = mlx_load_png("./img/open_door.png");
	img->img_wall = mlx_load_png("./img/wall.png");
	img->img_col = mlx_load_png("./img/key.png");
	img->img_bad = mlx_load_png("./img/enemy.png");
	ft_error_img(img);
}

/**
 * @brief  Funcion para liberar imagenes
 * 
 * @param img recibe las imagenes
 */
void	ft_delete_imgs(t_img_sprite *img)
{
	mlx_delete_texture(img->img_front);
	mlx_delete_texture(img->img_back);
	mlx_delete_texture(img->img_left);
	mlx_delete_texture(img->img_right);
	mlx_delete_texture(img->img_flat);
	mlx_delete_texture(img->img_close_door);
	mlx_delete_texture(img->img_open_door);
	mlx_delete_texture(img->img_wall);
	mlx_delete_texture(img->img_col);
	mlx_delete_texture(img->img_bad);
}
