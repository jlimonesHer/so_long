/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:04:10 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/11 17:08:16 by jlimones         ###   ########.fr       */
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
	mlx_texture_t	*img_close_door;
	mlx_texture_t	*img_open_door;
	mlx_texture_t	*img_wall;
	mlx_texture_t	*img_col;
	mlx_texture_t	*img_bad;
}	t_img_sprite;

/**
 * @brief lista de elementos para el PJ
 * mlx sera el puntero que inicia la ventana
 * img es la imagen del PJ
 * 
 */
typedef struct s_img_p
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_img_sprite	textures;
	int				x;
	int				y;
}	t_img_p;

enum e_size
{
	WIDTH = 800,
	HEIGHT = 400	
};

void		check_map(char *map, t_img_p posit);
void		ft_delete_imgs(t_img_sprite *img);
void		ft_save_imgs(t_img_sprite *img);
void		ft_generate_window(char *map, t_img_p *posit);
void		read_and_draw_map(char *map, t_img_sprite img, t_img_p *posit);
#endif