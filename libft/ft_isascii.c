/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:20:19 by jlimones          #+#    #+#             */
/*   Updated: 2022/09/22 16:12:28 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description:
The ft_isascii() tests if the value passed 
by parameter belongs to the ascii code.
*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
