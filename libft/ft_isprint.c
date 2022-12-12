/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:25:10 by jlimones          #+#    #+#             */
/*   Updated: 2022/09/20 16:54:35 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
La función isprint() comprueba cualquier carácter 
de impresión, incluido el espacio.
*/

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	else
		return (0);
}
