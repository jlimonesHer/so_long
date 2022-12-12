/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:59:10 by jlimones          #+#    #+#             */
/*   Updated: 2022/09/29 11:46:55 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < -9)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-(n / 10), fd);
		ft_putchar_fd(-(n % 10) + 48, fd);
	}
	else if (n > -10 && n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd(-n + 48, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd((n % 10 + 48), fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}
