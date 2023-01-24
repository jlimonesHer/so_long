/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:04:10 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/24 12:43:44 by jlimones         ###   ########.fr       */
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
# define INVADE 45
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
	mlx_texture_t	*img_col2;
	mlx_texture_t	*img_bad;
}	t_img_sprite;

typedef struct s_col_p
{
	int	visib;
	int	x;
	int	y;
}	t_col_p;

typedef struct s_items_p
{
	t_col_p	*cols;
	int		size_cols;
	int		x_bad;
	int		y_bad;
	int		x_door;
	int		y_door;
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
	int				open;
	int				count;
	mlx_image_t		*str_img;
}	t_img_p;

void		move_and_perspective_p(mlx_key_data_t keydata, void *param);
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
char		*ft_change_end_string(char *str);
int			ft_free_road(t_img_p *p_map);
void		ft_read_map(char *file, t_img_p *p_map);
void		ft_delete_map(t_img_p *p_map);
void		ft_draw_items(t_img_p *p_map);
int			ft_check_items(t_img_p *p_map, int p, int e, int c);
void		ft_error(char *error);
void		ft_error_fd(int fd);
#endif