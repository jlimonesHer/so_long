/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:49:37 by jlimones          #+#    #+#             */
/*   Updated: 2022/09/28 20:48:59 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_n(long long n)
{
	int	i;

	if (n < 0)
		n = n * -1;
	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_pos(int n2)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * n2 + 1);
	if (!str)
		return (NULL);
	str[n2] = '\0';
	return (str);
}

static char	*ft_neg(int n2)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * n2 + 2);
	if (!str)
		return (NULL);
	str[n2 + 1] = '\0';
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int				n2;
	long long		nlong;
	char			*str;

	nlong = (long long)n;
	n2 = ft_count_n(n);
	if (nlong < 0)
		str = ft_neg(n2);
	else
		str = ft_pos(n2);
	if (!str)
		return (NULL);
	while (0 < n2)
	{
		if (nlong < 0)
		{
			str[n2--] = ((nlong * -1) % 10) + 48;
		}
		else
			str[--n2] = (nlong % 10) + 48;
		nlong = nlong / 10;
	}
	return (str);
}
