/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:49:05 by jlimones          #+#    #+#             */
/*   Updated: 2023/01/12 16:41:59 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Libera memoria y cierra el archivo
 * 
 * @param fd numero del file descriptor
 * @param line linea leida por el get_next_line
 */
void	ft_close_and_free(int fd, char *line)
{
	free(line);
	close(fd);
}

/**
 * @brief Determina la posicion en el eje x en el mapa
 * 
 * @param map mapa .ber
 * @param totem recibe el carracter al que calcular la posicion
 * @return int eje x
 */
int	position_totem_x(char *map, char totem)
{
	size_t	fd;
	char	*line;
	int		i;
	int		x;

	x = 1;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i] && line[i] != totem)
			i++;
		if (line[i] == totem)
		{
			ft_close_and_free(fd, line);
			return (x * 55);
		}
		x++;
		free(line);
		line = get_next_line(fd);
	}
	ft_close_and_free(fd, line);
	return (0);
}

/**
 * @brief Determina la posicion en el eje x en el mapa
 * 
 * @param map mapa .ber
 * @param totem recibe el carracter al que calcular la posicion
 * @return int eje y
 */
int	position_totem_y(char *map, char totem)
{
	size_t	fd;
	char	*line;
	int		i;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 1;
		while (line[i] && line[i] != totem)
			i++;
		if (line[i] == totem)
		{
			ft_close_and_free(fd, line);
			return (i * 55);
		}
		free(line);
		line = get_next_line(fd);
	}
	ft_close_and_free(fd, line);
	return (0);
}

/**
 * @brief Esta funcion escribe las teclas pulsadas en la terminal 
 * 
 * @param keydata El numero de la tecla utilizada
 * @param move Struct de posiciones e imagenes del escenario
 */
void	ft_print_key(mlx_key_data_t keydata, t_img_p *move, mlx_texture_t *img)
{
	ft_printf("key: %i\n", keydata.key);
	mlx_draw_texture(move->img, img, move->x, move->y);
}

/**
 * @brief Funcion para desplazar el personaje
 * 
 * @param keydata recibe la key de las teclas
 * @param param parametro vacio
 */
void	move_and_perspective(mlx_key_data_t keydata, void *param)
{
	t_img_p		*move;

	move = (t_img_p *)param;
	if (keydata.key == MLX_KEY_W)
	{
		move->y -= 4;
		ft_print_key(keydata, move, move->textures.img_back);
	}
	else if (keydata.key == MLX_KEY_S)
	{
		move->y += 4;
		ft_print_key(keydata, move, move->textures.img_front);
	}
	else if (keydata.key == MLX_KEY_A)
	{
		move->x -= 4;
		ft_print_key(keydata, move, move->textures.img_left);
	}
	else if (keydata.key == MLX_KEY_D)
	{
		move->x += 4;
		ft_print_key(keydata, move, move->textures.img_right);
	}
}