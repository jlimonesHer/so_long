/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_delete_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:01:06 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/17 13:00:55 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_error_img(t_img_sprite *img)
{
	if (!img->img_front || !img->img_back || !img->img_left || !img->img_right
		|| !img->img_flat || !img->img_close_door || !img->img_open_door
		|| !img->img_wall || !img->img_col || !img->img_bad)
		ft_error("Falla al cargar una imagen\n");
}

/**
 * @brief Funcion para guardar las imagenes en una struck
 */
void	ft_save_imgs(t_img_sprite *img)
{
	img->img_front = mlx_load_png("./img/front_flat.png");
	img->img_back = mlx_load_png("./img/back_flat.png");
	img->img_left = mlx_load_png("./img/left_flat.png");
	img->img_right = mlx_load_png("./img/right_flat.png");
	img->img_flat = mlx_load_png("./img/flat_new.png");
	img->img_close_door = mlx_load_png("./img/close_door.png");
	img->img_open_door = mlx_load_png("./img/open_door.png");
	img->img_wall = mlx_load_png("./img/wall.png");
	img->img_col = mlx_load_png("./img/key.png");
	img->img_bad = mlx_load_png("./img/enemy.png");
	ft_error_img(img);
}

/**
 * @brief Funcion para liberar imagenes
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
/*
void	ft_display_img(void)
{
	t_img_sprite	img;
}
*/

/**
 * hacer funcion para controlar que los archivos pgn existen
	if (!img->img_front) printf("front\n");
	if (!img->img_back) printf("1\n");
	if (!img->img_left) printf("2\n");
	if (!img->img_right) printf("3\n");
	if (!img->img_flat) printf("4\n");
	if (!img->img_close_door) printf("5\n");
	if (!img->img_open_door) printf("6\n");
	if (!img->img_wall) printf("7\n");
	if (!img->img_col) printf("8\n");
	if (!img->img_bad) printf("9\n"); 
 */