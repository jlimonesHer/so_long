/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_delete_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:01:06 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/20 18:32:35 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Funcion para guardar las imagenes en una struck
 */
void	ft_save_imgs(t_img_sprite *img)
{
	img->img_front = mlx_load_png("./img/front_flat.png");
	img->img_back = mlx_load_png("./img/back_flat.png");
	img->img_left = mlx_load_png("./img/left_flat.png");
	img->img_right = mlx_load_png("./img/right_flat.png");
	img->img_flat = mlx_load_png("./img/flat2.png");
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
}
/*
void	ft_display_img(void)
{
	t_img_sprite	img;
}
*/