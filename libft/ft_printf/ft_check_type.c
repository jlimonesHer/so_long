/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:08:21 by jlimones          #+#    #+#             */
/*   Updated: 2022/10/10 08:43:14 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(char c, va_list lst)
{
	unsigned int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(lst, int));
	else if (c == '%')
		len = ft_putchar('%');
	else if (c == 's')
		len = ft_putstr(va_arg(lst, char *));
	else if (c == 'i')
		len = ft_putnbr_int(va_arg(lst, int));
	else if (c == 'd')
		len = ft_putnbr_int(va_arg(lst, long));
	else if (c == 'u')
		len = ft_putnbr_unsigned(va_arg(lst, unsigned int));
	else if (c == 'p')
	{
		len = ft_putstr("0x");
		len += ft_p_nbr_hex(HEXA, va_arg(lst, unsigned long));
	}
	else if (c == 'x')
		len = ft_p_nbr_hex(HEXA, va_arg(lst, unsigned int));
	else if (c == 'X')
		len = ft_p_nbr_hex(HEXADM, va_arg(lst, unsigned int));
	return (len);
}
