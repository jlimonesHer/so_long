/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:29:27 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/11 22:00:07 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief la funcion comprueba el caracter
 * Falta por posicionar el personaje(P) y el enemigo(caracter a elegir)
 * @param line linea leida por get_next_line
 * @param img struct para cargar los sprites
 */
static	void	ft_draw_pixel_map(char *line, t_img_sprite *img, t_img_p *p)
{
	int	i;

	i = 0;
	ft_save_imgs(img);
	p->x = 0;
	while (line[i])
	{
		if (line[i] == '0')
			mlx_draw_texture(p->img, img->img_flat, p->x, p->y);
		if (line[i] == '1')
			mlx_draw_texture(p->img, img->img_wall, p->x, p->y);
		if (line[i] == 'C')
			mlx_draw_texture(p->img, img->img_col, p->x, p->y);
		if (line[i] == 'E')
			mlx_draw_texture(p->img, img->img_close_door, p->x, p->y);
		if (line[i] == 'P')
			mlx_draw_texture(p->img, img->img_front, p->x, p->y);
		if (line[i] == 'B')
			mlx_draw_texture(p->img, img->img_close_door, p->x, p->y);
		p->x += 55;
		i++;
	}
	//printf("aqui3\n");
	//ft_delete_imgs(img);
}

/**
 * @brief 
 * 
 * @param map recibe el archivo .ber
 * @param img recibe los sprites para cargarlos
 */
void	read_and_draw_map(char *map, t_img_sprite img, t_img_p *posit)
{
	int		fd;
	//int		i;
	char	*line;

	//i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		printf("Erroooooooorrr");
	line = get_next_line(fd);
	posit->y = 0;
	posit->x = 0;
	while (line != NULL)
	{
		ft_draw_pixel_map(line, &img, posit);
		posit->y += 55;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
