/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:40:21 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/19 12:17:52 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	int			i;
	int			j;
	int			len;
	char		*str;

	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str || !s1 || !s2)
		return (0);
	str[len] = '\0';
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr_gnl(const char *str, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)str;
	i = 0;
	if (!str)
		return (NULL);
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}

void	ft_bzero_gnl(void *s, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = '\0';
		i++;
	}
}

void	*ft_calloc_gnl(unsigned int nmemb, unsigned int size)
{
	void			*ptr;
	unsigned int	total_size;

	total_size = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb * size > INT_MAX)
		return (0);
	ptr = malloc(total_size);
	if (!ptr)
		return (0);
	ft_bzero_gnl(ptr, total_size);
	return (ptr);
}
