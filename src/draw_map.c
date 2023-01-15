/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:29:27 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/15 12:46:31 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief la funcion comprueba el caracter
 * Falta por posicionar el personaje(P) y el enemigo(caracter a elegir)
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
 * @brief 
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
