/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 08:06:11 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/14 13:09:19 by jlimones         ###   ########.fr       */
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

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			return (str);
		}
		i++;
	}
	return (str);
}

/**
 * @brief Funcion para guardar el mapa en una matriz
 * 
 * @param map recibe el mapa.ber
 */
void	ft_read_map(char *file, t_img_p *p_map)
{
	int		fd;
	int		i;

	p_map->map = malloc(sizeof(char *) * p_map->height);
	i = 0;
	fd = open(file, O_RDONLY);
	p_map->map[i] = ft_change_end_string(get_next_line(fd));
	while (p_map->map[i] != NULL)
		p_map->map[++i] = ft_change_end_string(get_next_line(fd));
}


void	ft_delete_map(t_img_p *p_map)
{
	int	i;

	i = 0;
	while (i < p_map->height)
		free(p_map->map[i++]);
	free(p_map->map);
}
