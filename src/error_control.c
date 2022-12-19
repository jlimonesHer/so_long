/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:18:16 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/19 11:58:01 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

/**
 * @brief funcion para contorlar que el archivo pasado por parametro 
 * contenga el .ber
 * Si el nnumero de parametros no es correcto no se iniciara el programa
 * @param argv 
 * @return int 
 */
int	ft_control_file(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	if (ft_strnstr(argv[1], ".ber", 4) == 0)
		return (1);
	return (0);
}
