/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 07:53:19 by jlimones          #+#    #+#             */
/*   Updated: 2022/09/27 08:43:44 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;

	d = malloc (ft_strlen(s) + 1);
	if (d == NULL)
		return (NULL);
	ft_memcpy (d, s, ft_strlen(s) + 1);
	return (d);
}
