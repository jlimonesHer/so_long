/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:01:42 by jlimones          #+#    #+#             */
/*   Updated: 2022/10/10 08:22:29 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(char const *str, ...)
{
	va_list	lst;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(lst, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += ft_check_type(str[i + 1], lst);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
	i++;
	}
	va_end(lst);
	return (len);
}
