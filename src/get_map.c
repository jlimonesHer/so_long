/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:29:47 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/20 09:21:36 by jlimones         ###   ########.fr       */
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
	return (res);
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
	if (!check_lines(fd, map))
		ft_printf("Las lineas son correctas");
	else
	 ft_printf("Las lineas NO son correctas");
	//ft_get_line_fd(fd, map);
	//buffer = get_next_line(fd);
	//printf("%s\n", buffer);
}
