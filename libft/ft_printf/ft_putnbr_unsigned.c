/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:54:30 by jlimones          #+#    #+#             */
/*   Updated: 2022/10/10 08:28:59 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putnbr_unsigned(unsigned long nb)
{
	long			numb;
	unsigned int	len;

	len = 0;
	numb = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		len++;
		numb *= -1;
	}
	if (numb <= 9)
	{
		ft_putchar((numb + '0'));
		len++;
	}
	else
	{
		len += ft_putnbr_int(numb / 10);
		ft_putchar((numb % 10) + '0');
		len++;
	}
	return (len);
}
