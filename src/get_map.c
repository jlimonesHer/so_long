/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:29:47 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/20 12:02:44 by jlimones         ###   ########.fr       */
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
static	int	check_lines(int fd, char *map)
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
	len_lines = ft_strlen(fd_lines);
	while (fd_lines != NULL && res == 0)
	{
		len_lines = ft_strlen(fd_lines);
		if (len != len_lines)
			res = 1;
		fd_lines = get_next_line(fd);
	}
	free(line);
	free(fd_lines);
	close(fd);
	return (res);
}

/**
 * @brief Comprueba que el mapa sea un rectangulo
 * 
 * @param fd recibe el fd del fichero a leer
 * @param map recibe la ruta al fichero
 * @return int / Numero de lineas que contiene el mapa
 */
static	int	check_rectangle(int fd, char *map)
{
	int		len;
	int		total_line;
	char	*line;

	total_line = 1;
	if (!check_lines(fd, map))
	{
		fd = open(map, O_RDONLY);
		line = get_next_line(fd);
		len = ft_strlen(line);
		while (line != NULL)
		{
			line = get_next_line(fd);
			total_line++;
			free(line);
		}
		if (total_line == len && total_line < 4)
			total_line = 0;
		free(line);
	}
	close(fd);
	return (total_line - 1);
}


/**
 * @brief Esta funcion lee el archivo 
 * 
 * @param fd recibe el fd del archivo(mapa)
 * @param map recibe la ruta al archivo que contiene el mapa
 */
static void	ft_get_line_fd(int fd, char *map)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
}

/**
 * @brief Funcion para leer el mapa
 * 
 * @param map ruta al archivo .ber recibido por parametro
 * @return int 
 */
void	read_map(char *map)
{
	size_t	fd;
	size_t	map1;
	char	*buffer;

	fd = open(map, O_RDONLY);
	if (check_rectangle(fd, map) < 4)
		ft_printf("El mapa no es correcto\n");
	else
		ft_printf("El mapa es correcto\n");
}
