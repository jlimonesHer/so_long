/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_nbr_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:25:58 by jlimones          #+#    #+#             */
/*   Updated: 2022/10/07 15:17:48 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_p_nbr_hex(const char *str, unsigned long long n)
{
	unsigned int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_p_nbr_hex(str, n / 16);
		len += ft_p_nbr_hex(str, n % 16);
	}
	else
	{	
		ft_putchar(str[n]);
		len++;
	}
	return (len);
}
