/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:21:31 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/02 14:32:21 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXA "0123456789abcdef"
# define HEXADM "0123456789ABCDEF"
# include <stdarg.h>
# include <unistd.h>
# include "../libft.h"

int				ft_printf(const char *str, ...);
int				ft_putchar(char c);
unsigned int	ft_putnbr_int(int nb);
unsigned int	ft_putnbr_unsigned(unsigned long n);
unsigned int	ft_p_nbr_hex(const char *str, unsigned long long n);
int				ft_putstr(char *str);
int				ft_check_type(char c, va_list lst);

#endif