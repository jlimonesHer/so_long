/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:29:47 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/19 13:00:38 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(char *map)
{
	size_t	fd;
	size_t	map1;
	char	buffer[1042];

	fd = open(map, O_RDONLY);

		get_next_line(fd);
		//printf("read = %s\nfd = %zu\n", map, fd);

	return (0);
}
