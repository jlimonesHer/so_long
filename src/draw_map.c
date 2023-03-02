/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:29:27 by jlimones          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/13 15:03:24 by jlimones         ###   ########.fr       */
=======
/*   Updated: 2023/01/24 12:14:09 by jlimones         ###   ########.fr       */
>>>>>>> e397e74c1f03a57c09a84d30986a2c1e6cd51e62
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief la funcion comprueba el caracter y pinta los muros o el fondo
 * 
 * @param line linea leida por get_next_line
 * @param img struct para cargar los sprites
 */
static	void	ft_draw_pixel_map(char *line, t_img_sprite *img,
		t_img_p *p_map, int y)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '1')
			mlx_draw_texture(p_map->img, img->img_wall, x, y);
		else
			mlx_draw_texture(p_map->img, img->img_flat, x, y);
		x += PIXEL;
		i++;
	}
}

/**
 * @brief lee el mapa para darle el tamaño y pintarlo
 * 
 * @param map recibe el archivo .ber
 * @param img recibe los sprites para cargarlos
 */
void	read_and_draw_map(char *file, t_img_sprite img, t_img_p *p_map)
{
	int		fd;
	char	*line;
	int		y;

	y = 0;
	fd = open(file, O_RDONLY);
	ft_error_fd(fd);
	line = get_next_line(fd);
	while (line != 0)
	{
		ft_draw_pixel_map(line, &img, p_map, y);
		y += PIXEL;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
