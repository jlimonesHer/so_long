/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:48:09 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/04 11:28:54 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Funcion error personalizado
 * 
 * @param error String a mostrar por terminal
 */
void	ft_error(char *error)
{
	ft_putstr_fd(error, 2);
	exit(-1);
}

/**
 * @brief funcion de error estandar
 * 
 * @param fd 
 */
void	ft_error_fd(int fd)
{
	if (fd < 0)
	{
		ft_putstr_fd("Algo ha fallado al leer el archivo\n", 2);
		exit(-1);
	}
}
