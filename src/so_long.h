/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:04:10 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/20 19:00:18 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Input.h"
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/GNL/get_next_line.h"

/**
 * @brief Struct para guardar las imagenes
 */
typedef struct s_img_sprite
{
	mlx_texture_t	*img_front;
	mlx_texture_t	*img_back;
	mlx_texture_t	*img_left;
	mlx_texture_t	*img_right;
	mlx_texture_t	*img_flat;
}	t_img_sprite;

/**
 * @brief lista de elementos para el PJ
 * mlx sera el puntero que inicia la ventana
 * img es la imagen del PJ
 * 
 */
typedef struct s_position
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_img_sprite	textures;
	int				x;
	int				y;
}	t_position;


enum e_size
{
	WIDTH = 800,
	HEIGHT = 400	
};

void		read_map(char *map, t_position posit);
void		ft_delete_imgs(t_img_sprite *img);
void		ft_save_imgs(t_img_sprite *img);
#endif