/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:13:54 by jlimones          #+#    #+#             */
/*   Updated: 2022/09/22 18:02:53 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description:
The ft_isdigit() tests if the value passed by parameter is a numeric 
character from the ascii code.
*/

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		c = 1;
	else
		c = 0;
	return (c);
}
