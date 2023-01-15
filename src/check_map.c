/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:29:47 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/15 11:33:30 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Comprueba que todas las lineas tengan el mismo largo
 * 
 * @param p_map struck con las variables iniciadas
 * @return size_t 1 si es correcto ,0 si no lo es
 */
static	size_t	check_lines_matrix(t_img_p *p_map)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(p_map->map[0]);
	while (i < p_map->height && len == ft_strlen(p_map->map[i]))
		i++;
	if (i == p_map->height)
		return (1);
	return (0);
}

/**
 * @brief Comprueba que las lineas laterales sean muros
 * 
 * @param p_map struck con variables inicializadas en ft_init_p_map
 * @return int size_t 1 si es correcto ,0 si no lo es
 */
static int	check_wall_up_donw(t_img_p *p_map)
{
	int	i;

	i = 0;
	while (p_map->map[0][i] == '1' && p_map->map[p_map->height - 1][i] == '1')
		i++;
	if (i == p_map->width)
		return (1);
	return (0);
}

/**
 * @brief comprueba que la primera fila y la ultima sean muros
 * 
 * @param p_map  struck con variables inicializadas en ft_init_p_map
 * @return int size_t 1 si es correcto ,0 si no lo es
 */
static int	check_wall_left_right(t_img_p *p_map)
{
	int	i;

	i = 0;
	while (p_map->height > i && p_map->map[i][p_map->width - 1] == '1'
			&& p_map->map[i][0] == '1')
		i++;
	if (i == p_map->height)
		return (1);
	return (0);
}

/**
 * @brief Comprueba que al menos 1 objeto de cada tipo
 * 
 * @param p_map struck con variables inicializadas en ft_init_p_map
 * @param p posiciones iniciales disponibles en el mapa
 * @param e Salidas disponibles en el mapa
 * @param c coleccionables disponibles en el mapa
 * @return int size_t 1 si es correcto ,0 si no lo es
 */
static int	ft_check_items(t_img_p *p_map, int p, int e, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (p_map->height > i)
	{
		j = 0;
		while (p_map->map[i][j])
		{
			if (p_map->map[i][j] == 'P')
				p++;
			else if (p_map->map[i][j] == 'E')
				e++;
			else if (p_map->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (p > 0 && e > 0 && c > 0)
		return (1);
	return (0);
}

void	check_map(t_img_p *p_map)
{
	if (check_lines_matrix(p_map) && check_wall_up_donw(p_map)
		&& check_wall_left_right(p_map) && ft_check_items(p_map, 0, 0, 0))
		printf("El mapa es correcto\n");
	else
		printf("El mapa no es correcto\n");
	//printf("check_wall_up_m = %i\n", check_wall_up_donw(p_map));
	//printf("check_wall_left_m = %i\n", check_wall_left_right(p_map));
	//printf("check_lines_m = %zu\n", check_lines_matrix(p_map));
	//printf("check_items_m = %i\n", ft_check_items(p_map, 0, 0, 0));
}
