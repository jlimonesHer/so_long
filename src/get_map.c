/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:29:47 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/19 19:15:53 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	count_line(int fd, char *map)
{
	int		len;
	int		len_lines;
	char	*line;

	line = get_next_line(fd);
	len = ft_strlen(line);
	while (len )
	{
		len_lines = ft_strlen(line)
		len = ft_strlen(get_next_line(fd));
		
	}
}

/**
 * @brief Esta funcion leee el archivo 
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
	while (line != NULL)
	{
		
	}
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
	ft_get_line_fd(fd, map);
	//buffer = get_next_line(fd);
	//printf("%s\n", buffer);
}
