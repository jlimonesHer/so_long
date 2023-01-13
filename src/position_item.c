/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_item.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:49:10 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/13 18:13:44 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Libera memoria y cierra el archivo
 * 
 * @param fd numero del file descriptor
 * @param line linea leida por el get_next_line
 */
void	ft_close_and_free(int fd, char *line)
{
	free(line);
	close(fd);
}

/**
 * @brief Determina la posicion en el eje x en el mapa
 * 
 * @param map mapa .ber
 * @param totem recibe el carracter al que calcular la posicion
 * @return int eje y
 */
int	position_item_x(char *map, char totem)
{
	size_t	fd;
	char	*line;
	int		i;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 1;
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
	return (0);
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
	int		x;

	x = 1;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i] && line[i] != totem)
			i++;
		if (line[i] == totem)
		{
			ft_close_and_free(fd, line);
			return (x);
		}
		x++;
		free(line);
		line = get_next_line(fd);
	}
	ft_close_and_free(fd, line);
	return (0);
}
