/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_item.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:49:10 by jlimones          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/13 15:50:14 by jlimones         ###   ########.fr       */
=======
/*   Updated: 2023/02/04 11:23:42 by jlimones         ###   ########.fr       */
>>>>>>> e397e74c1f03a57c09a84d30986a2c1e6cd51e62
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief localiza el eje 'y' objeto pasado por parametro
 * 
 * @param p_map struck con variables inicializadas
 * @param obj objeto a localizar
 * @return int posicion  en el mapa
 */
int	position_item_y_matrix(t_img_p *p_map, char obj)
{
<<<<<<< HEAD
	free(line);
	close(fd);
}

/**
 * @brief Determina la posicion en el eje x en el mapa
 * 
 * @param map mapa .ber
 * @param totem recibe el carracter al que calcular la posicion
 * @return int eje x
 */
int	position_item_y(char *map, char totem)
{
	size_t	fd;
	char	*line;
	int		i;
	int		y;

	y = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	printf("line GNL y: %s\n", line);
	while (line != NULL)
	{
		i = 0;
		while (line[i] && line[i] != totem)
			i++;
		if (line[i] == totem)
		{
			ft_close_and_free(fd, line);
			return (y);
		}
		y++;
		free(line);
		line = get_next_line(fd);
=======
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < p_map->height && p_map->map[y][x] != obj)
	{
		x = 0;
		while (x < p_map->width && p_map->map[y][x] != obj)
			x++;
		if (p_map->map[y] != 0 && p_map->map[y][x] != obj)
			y++;
>>>>>>> e397e74c1f03a57c09a84d30986a2c1e6cd51e62
	}
	if (y >= p_map->height)
		ft_error("Uno o varios objetos estan mal colocados\n");
	if (p_map->map[y][x] == obj)
		return (y + 1);
	ft_error("Uno o varios objetos estan mal colocados\n");
	return (0);
}

/**
 * @brief localiza el eje 'x' objeto pasado por parametro
 * 
 * @param p_map struck con variables inicializadas
 * @param obj objeto a localizar
 * @return int posicion x en el mapa
 */
<<<<<<< HEAD
int	position_item_x(char *map, char totem)
=======
int	position_item_x_matrix(t_img_p *p_map, char obj)
>>>>>>> e397e74c1f03a57c09a84d30986a2c1e6cd51e62
{
	int	x;
	int	y;

<<<<<<< HEAD
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	printf("line GNL x: %s\n", line);
	while (line != NULL)
	{
		i = 0;
		while (line[i] && line[i] != totem)
			i++;
		if (line[i] == totem)
		{
			ft_close_and_free(fd, line);
			return (i);
		}
		free(line);
		line = get_next_line(fd);
	}
	ft_close_and_free(fd, line);
=======
	if (obj == 'P')
		y = (p_map->y) / PIXEL;
	else if (obj == 'B')
		y = (p_map->p_items.y_bad) / PIXEL;
	else if (obj == 'E')
		y = (p_map->p_items.y_door) / PIXEL;
	x = 0;
	while (x < p_map->width && p_map->map[y][x] != obj)
		x++;
	if (p_map->map[y][x] == obj)
		return (x);
>>>>>>> e397e74c1f03a57c09a84d30986a2c1e6cd51e62
	return (0);
}
