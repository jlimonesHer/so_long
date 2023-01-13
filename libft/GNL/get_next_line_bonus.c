/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:40:28 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/13 17:52:52 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buff[4096];
	char		*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0 || fd > 4096)
	{
		free(buff[fd]);
		buff[fd] = NULL;
		return (0);
	}
	buff[fd] = ft_read(fd, buff[fd]);
	if (!buff[fd])
		return (0);
	str = ft_get_line(buff[fd]);
	buff[fd] = ft_get_static(buff[fd]);
	return (str);
}

char	*ft_mod_join(char *buff, char *tmp)
{
	char	*join;

	join = ft_strjoin_get(buff, tmp);
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
	line = ft_calloc_get(i + 2, sizeof(char));
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
		buff = ft_calloc_get(1, 1);
	tmp_buff = ft_calloc_get(BUFFER_SIZE + 1, sizeof(char));
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
		if (ft_strchr_get(buff, '\n'))
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
	n_buffer = ft_calloc_get(ft_strlen_get(buff) - i + 1, sizeof(char));
	if (!n_buffer)
		return (0);
	i++;
	while (buff[i])
		n_buffer[j++] = buff[i++];
	n_buffer[j] = '\0';
	free(buff);
	return (n_buffer);
}
