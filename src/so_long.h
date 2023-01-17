/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:04:10 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/17 15:08:50 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Input.h"
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

# define PIXEL 55
# define MOVE 11
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

typedef struct s_items_p
{
	int	x_col;
	int	y_col;
	int	x_bad;
	int	y_bad;
	int	x_door;
	int	y_door;
}	t_items_p;

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
	t_items_p		p_items;
	char			**map;
	char			*file;
	int				x;
	int				y;
	int				height;
	int				width;
	int				v_bool;
}	t_img_p;

void		move_and_perspective(mlx_key_data_t keydata, void *param);
void		check_map(t_img_p *p_map);
void		ft_delete_imgs(t_img_sprite *img);
void		ft_save_imgs(t_img_sprite *img);
int			ft_lenght_x(char *file);
int			ft_lenght_y(char *file);
void		read_and_draw_map(char *file, t_img_sprite img, t_img_p *posit);
void		ft_generate_window(char *file, t_img_p *p_map);
int			position_item_y_matrix(t_img_p *p_map, char obj);
int			position_item_x_matrix(t_img_p *p_map, char obj);
void		ft_init_p_map(char *file, t_img_p *p_map);
void		ft_init_item(t_img_p *p_map);
void		ft_read_map(char *file, t_img_p *p_map);
void		ft_delete_map(t_img_p *p_map);
void		ft_draw_items(t_img_p *p_map);
void		ft_error(char *error);
void		ft_error_fd(int fd);
#endif