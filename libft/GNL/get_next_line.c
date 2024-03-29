/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:40:28 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/19 12:57:37 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	buff = ft_read(fd, buff);
	if (!buff)
		return (0);
	str = ft_get_line(buff);
	buff = ft_get_static(buff);
	return (str);
}

char	*ft_mod_join(char *buff, char *tmp)
{
	char	*join;

	join = ft_strjoin_gnl(buff, tmp);
	free(buff);
	return (join);
}

char	*ft_get_line(char *buff)
{
	int		i;
	char	*line;

	i = 0;
	if (!buff[i])
		return (0);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = ft_calloc_gnl(i + 2, sizeof(char));
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i])
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *buff)
{
	char	*tmp_buff;
	int		read_size;

	if (!buff)
		buff = ft_calloc_gnl(1, 1);
	tmp_buff = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, tmp_buff, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(tmp_buff);
			return (0);
		}
		tmp_buff[read_size] = '\0';
		buff = ft_mod_join(buff, tmp_buff);
		if (ft_strchr_gnl(buff, '\n'))
		{
			free(tmp_buff);
			return (buff);
		}
	}
	free(tmp_buff);
	return (buff);
}

char	*ft_get_static(char *buff)
{
	int		i;
	int		j;
	char	*n_buffer;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (0);
	}
	n_buffer = ft_calloc_gnl(ft_strlen_gnl(buff) - i + 1, sizeof(char));
	if (!n_buffer)
		return (0);
	i++;
	while (buff[i])
		n_buffer[j++] = buff[i++];
	n_buffer[j] = '\0';
	free(buff);
	return (n_buffer);
}
