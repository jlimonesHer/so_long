/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 08:06:11 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/14 08:16:03 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Funcion para cambiar el salto d linea por el final de cadena
 * 
 * @param str  recibe la cadena a modificar
 * @return char* 
 */
static char	*ft_change_end_string(char *str)
{
	int		i;

	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			return (str);
		}
		i++;
	}
}

/**
 * @brief Funcion para guardar el mapa en una matriz
 * 
 * @param map recibe el mapa.ber
 */
void	ft_read_map(char *map)
{
	int		fd;
	int		i;
	char	**m_map;

	m_map = malloc(sizeof(char *) * ft_lenght_y(map));
	i = 0;
	fd = open(map, O_RDONLY);
	m_map[i] = get_next_line(fd);
	while (m_map[i] != NULL)
		m_map[++i] = ft_change_end_string(get_next_line(fd));
}
