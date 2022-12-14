/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:04:10 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/14 14:46:40 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Input.h"
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

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
	mlx_texture_t	*texture;
	int				x;
	int				y;
}	t_position;

typedef struct s_flat
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;
	int				x;
	int				y;
}	t_flat;
#endif