/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:52:53 by jlimones          #+#    #+#             */
/*   Updated: 2022/09/22 19:24:41 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	unsigned long	y;

	y = ft_strlen(src);
	if (size <= 0)
		return (y);
	while ((size-- > 1) && (*src))
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (y);
}
