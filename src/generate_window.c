/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:08:52 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/11 17:31:22 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	ft_lenght_x(char *map)
{
	int		len;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	len = ft_strlen(line);
	free(line);
	close(fd);
	return (len);
}

static	int	ft_lenght_y(char *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

void	ft_generate_window(char *map, t_img_p *posit)
{
	int		width;
	int		height;

	width = 55 * ft_lenght_x(map);
	height = 55 * ft_lenght_y(map);
	//posit->mlx = mlx_init(width, height, "So_long", false);
	printf("aqui\n");
	read_and_draw_map(map, posit->textures, posit);
	posit->img = mlx_new_image(posit->mlx, width, height);
}
