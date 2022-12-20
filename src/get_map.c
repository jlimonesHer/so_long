/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:29:47 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/20 16:58:47 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Chekea que todas las lineas sean del mismo tamaño
 * 
 * @param fd recibe el fd del fichero a leer
 * @param map recibe la ruta al fichero
 * @return devuelve 0 si las lineas son iguales o 1 en caso contrario.
 */
static	int	check_lines(int fd)
{
	int		len;
	int		len_lines;
	char	*line;
	char	*fd_lines;
	int		res;

	res = 0;
	line = get_next_line(fd);
	fd_lines = get_next_line(fd);
	len = ft_strlen(line);
	free(line);
	len_lines = ft_strlen(fd_lines);
	while (fd_lines != NULL && res == 0)
	{
		len_lines = ft_strlen(fd_lines);
		free(fd_lines);
		if (len != len_lines)
			res = 1;
		fd_lines = get_next_line(fd);
	}
	free(fd_lines);
	close(fd);
	return (res);
}

/**
 * @brief 
 * 
 * @param fd 
 * @param map 
 * @param posit 
 * @return int 
 */
static	int	check_obj(int fd, t_position posit)
{
	int		c;
	int		e;
	int		i;
	char	*line;

	e = 0;
	c = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = -1;
		while (line[++i])
		{
			if (line[i] == 'E')
				c++;
			if (line[i] == 'C')
				e++;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (c < 0 && e < 0 && posit.x < 0 && posit.y < 0)
		return (1);
	return (0);
}

/**
 * @brief Comprueba que el mapa sea un rectangulo
 * 
 * @param fd recibe el fd del fichero a leer
 * @param map recibe la ruta al fichero
 * @return int / Numero de lineas que contiene el mapa
 */
static	int	check_rectangle(int fd, char *map, t_position posit)
{
	int		len;
	int		total_line;
	char	*line;

	total_line = 1;
	if (!check_lines(fd) && check_obj(fd, posit) == 0)
	{
		fd = open(map, O_RDONLY);
		line = get_next_line(fd);
		len = ft_strlen(line);
		free(line);
		while (line != NULL)
		{
			line = get_next_line(fd);
			total_line++;
			free(line);
		}
		if (total_line == len && total_line < 4)
			total_line = 0;
	}
	close(fd);
	return (total_line - 1);
}

/**
 * @brief Funcion para leer el mapa
 * 
 * @param map ruta al archivo .ber recibido por parametro
 * @return int 
 */
void	read_map(char *map, t_position posit)
{
	size_t	fd;

	fd = open(map, O_RDONLY);
	if (check_rectangle(fd, map, posit) < 4)
		perror("Error");
}
