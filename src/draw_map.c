/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:29:27 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/13 18:15:59 by jlimones         ###   ########.fr       */
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
	while (line[i])
	{
		if (line[i] == 'P')
			mlx_draw_texture(p_map->img, img->img_front, x, y);
		else if (line[i] == '1')
			mlx_draw_texture(p_map->img, img->img_wall, x, y);
		else
			mlx_draw_texture(p_map->img, img->img_flat, x, y);
		x += 55;
		i++;
	}
}

/**
 * @brief 
 * 
 * @param map recibe el archivo .ber
 * @param img recibe los sprites para cargarlos
 */
void	read_and_draw_map(char *map, t_img_sprite img, t_img_p *p_map)
{
	int		fd;
	char	*line;
	int		y;

	y = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		printf("Error al leer el mapa");
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_draw_pixel_map(line, &img, p_map, y);
		y += 55;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
