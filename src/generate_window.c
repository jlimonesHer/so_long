/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:08:52 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/15 12:01:35 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief funcion para contar las lineas de un mapa
 * 
 * @param map recibe el mapa .ber
 * @return int del numero de lineas
 */
int	ft_lenght_y(char *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

/**
 * @brief Funcion para contar los caracteres de una linea
 * 
 * @param map recibe el mapa .ber
 * @return int el numero de caracteres
 */
int	ft_lenght_x(char *map)
{
	int		len;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	len = ft_strlen(line) - 1;
	free(line);
	close(fd);
	return (len);
}

/**
 * @brief Esta funcion calcula y muestra las medidas del mapa .ber
 * 
 * @param map Recibe el archivo .ber
 */
void	ft_generate_window(char *map, t_img_p *p_map)
{
	ft_save_imgs(&p_map->textures);
	p_map->mlx = mlx_init(PIXEL * p_map->width, PIXEL * p_map->height,
			"So_long", 1);
	p_map->img = mlx_new_image(p_map->mlx, PIXEL * p_map->width,
			PIXEL * p_map->height);
	if (!p_map->img)
		ft_printf("error\n");
	check_map(p_map);
	mlx_key_hook(p_map->mlx, move_and_perspective, p_map);
	mlx_image_to_window(p_map->mlx, p_map->img, 0, 0);
	read_and_draw_map(map, p_map->textures, p_map);
	mlx_draw_texture(p_map->img, p_map->textures.img_front, p_map->x, p_map->y);
	mlx_loop(p_map->mlx);
	ft_delete_map(p_map);
	ft_delete_imgs(&p_map->textures);
	mlx_terminate(p_map->mlx);
	ft_error(p_map, "El programa se ha cerrado correctamente\n");
}
