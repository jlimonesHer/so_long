/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:08:52 by jlimones          #+#    #+#             */
/*   Updated: 2023/03/02 18:08:51 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

/**
 * @brief Funcion para contar los caracteres de una linea
 * 
 * @param map recibe el mapa .ber
 * @return int el numero de caracteres
 */
int	ft_width(char *map)
{
	int		len;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	printf("line : %s\n", line);
	len = ft_strlen(line);
	printf("strlen : %i\n", len);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (len);
}

/**
 * @brief funcion para contar las lineas de un mapa
 * 
 * @param map recibe el mapa .ber
 * @return int del numero de lineas
 */
int	ft_height(char *map)
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
	len = ft_strlen(line);
	free(line);
	close(fd);
	return (i);
}

/**
 * @brief Esta funcion calcula y muestra las medidas del mapa .ber y mas cosas
 * 
 * @param map Recibe el archivo .ber
 */
void	ft_generate_window(t_img_p *p_map)
{
	p_map->mlx = mlx_init(p_map->width, p_map->height,
			"So_long", false);
	p_map->img = mlx_new_image(p_map->mlx, p_map->width, p_map->height);
	printf("x : %i, y : %i\n", p_map->x, p_map->y);
	if (!p_map->img)
		ft_printf("error\n");
	mlx_key_hook(p_map->mlx, move_and_perspective, p_map);
	mlx_image_to_window(p_map->mlx, p_map->img, 0, 0);
	read_and_draw_map(p_map->map, p_map->textures, p_map);
	mlx_loop(p_map->mlx);
	ft_delete_imgs(&p_map->textures);
	mlx_terminate(p_map->mlx);
}
