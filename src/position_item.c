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
/*   Updated: 2023/01/13 17:56:33 by jlimones         ###   ########.fr       */
>>>>>>> 7d83d99... Empezar aqui
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
<<<<<<< HEAD
	printf("line GNL y: %s\n", line);
=======
>>>>>>> 7d83d99... Empezar aqui
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
	}
	ft_close_and_free(fd, line);
	return (0);
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
<<<<<<< HEAD
	printf("line GNL x: %s\n", line);
=======
>>>>>>> 7d83d99... Empezar aqui
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
	return (0);
}
