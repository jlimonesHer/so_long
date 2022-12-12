/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:51:09 by jlimones          #+#    #+#             */
/*   Updated: 2022/09/20 16:20:57 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description:
The ft_alpha() tests if the value passed by parameter is an alphabetic character.
*/

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		c = 1;
	else
		c = 0;
	return (c);
}
