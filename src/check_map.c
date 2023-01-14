/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:29:47 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/14 13:48:04 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Comprueba que todas las lineas tengan el mismo largo
 * 
 * @param p_map struck con las variables iniciadas
 * @return size_t 
 */
static	size_t	check_lines_matrix(t_img_p *p_map)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(p_map->map[0]);
	while (i < p_map->height && len == ft_strlen(p_map->map[i]))
		i++;
	if (i != p_map->height)
		return (1);
	return (0);
}

static int	check_wall(t_img_p *p_map)
{
	int	i;

	i = 0;
	printf("map[0] = %s, map[height = %s\n", p_map->map[0], p_map->map[p_map->height - 1]);
	while (p_map->map[0][i] == '1' && p_map->map[p_map->height - 1][i] == '1')
		i++;
		return(printf("largo %i", i));
}

/**
 * @brief Comprueba que el mapa sea un rectangulo
 * 
 * @param fd recibe el fd del fichero a leer
 * @param map recibe la ruta al fichero
 * @return int / Numero de lineas que contiene el mapa
 */
// static	int	check_rectangle(int fd, char *map, t_img_p *p_map)
// {
// 	int		len;
// 	int		total_line;
// 	char	*line;

// 	total_line = 1;
// 	if (!(check_lines_matrix(p_map) == 1) && (check_obj(fd, map, p_map) == 0))
// 	{
// 		fd = open(map, O_RDONLY);
// 		line = get_next_line(fd);
// 		len = ft_strlen(line);
// 		free(line);
// 		while (line != NULL)
// 		{
// 			line = get_next_line(fd);
// 			total_line++;
// 			free(line);
// 		}
// 		if (total_line == len && total_line < 4)
// 			total_line = 0;
// 	}
// 	close(fd);
// 	return (total_line - 1);
// }

/**
 * @brief Funcion para leer el mapa
 * 
 * @param map ruta al archivo .ber recibido por parametro
 * @return int 
 */
void	check_map(char *file, t_img_p *p_map)
{
	size_t	fd;


	fd = open(file, O_RDONLY);
	check_wall(p_map);
	printf("check_lines_m = %zu\n", check_lines_matrix(p_map));
	// if (check_rectangle(fd, file, p_map) < 4)
	// {
	// 	ft_printf("Can't read the map\n");
	// 	exit(-1);
	// 	//Funcion para terminar el programa
	// }
	close(fd);
}
