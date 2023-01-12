/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:08:52 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/12 16:26:18 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	len = ft_strlen(line);
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
int	ft_lenght_y(char *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
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
 * @brief Calcula las medidas pasadas en el mapa .ber
 * 
 * @param map recibe el mapa .ber
 * @param posit pasamaos la imagenes cargadas
 */
void	ft_generate_map(char *map, t_img_p *posit)
{
	int		width;
	int		height;

	width = 55 * ft_lenght_x(map);
	height = 55 * ft_lenght_y(map);
	read_and_draw_map(map, posit->textures, posit);
	posit->img = mlx_new_image(posit->mlx, width, height);
}

/**
 * @brief Esta funcion calcula y muestra las medidas del mapa .ber
 * 
 * @param map Recibe el archivo .ber
 */
void	ft_generate_window(char *map)
{
	t_img_p	posit;

	posit.x = (ft_lenght_x(map) * 55);
	posit.y = (ft_lenght_y(map) * 55);
	check_map(map, posit);
	posit.mlx = mlx_init(posit.x - 55, posit.y - 55, "So_long", true);
	posit.img = mlx_new_image(posit.mlx, posit.x, posit.y);
	if (!posit.img)
		ft_printf("error\n");
	mlx_key_hook(posit.mlx, move_and_perspective, &posit);
	mlx_image_to_window(posit.mlx, posit.img, 0, 0);
	ft_generate_map(map, &posit);
	mlx_loop(posit.mlx);
	ft_delete_imgs(&posit.textures);
	mlx_terminate(posit.mlx);
}
