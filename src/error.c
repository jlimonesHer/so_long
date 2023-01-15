/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:48:09 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/15 12:08:11 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Funcion para controlar errores
 * 
 * @param p_map se pasa el puntero mlx para cerrar le loop correctamente
 * @param error String a mostrar por terminal
 */
void	ft_error(t_img_p *p_map, char *error)
{
	ft_printf(error);
	mlx_close_window(p_map->mlx);
}