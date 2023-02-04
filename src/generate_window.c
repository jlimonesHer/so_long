/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:08:52 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/04 11:24:48 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief funcion para contar las lineas de un mapa
 * 
 * @param map recibe el mapa .ber
 * @return int del numero de lineas
 */
int	ft_lenght_y(char *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	ft_error_fd(fd);
	while (line != 0)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

/**
 * @brief Funcion para contar los caracteres de una linea
 * 
 * @param map recibe el mapa .ber
 * @return int el numero de caracteres
 */
int	ft_lenght_x(char *map)
{
	int		len;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	ft_error_fd(fd);
	line = get_next_line(fd);
	len = ft_strlen(line) - 1;
	free(line);
	close(fd);
	return (len);
}

/**
 * @brief comprueba cuantos coleccionables quedan en el 
 * mapa y cambia su condicion de visible
 * 
 * @param p_map recibe la struck inicializada
 */
static	void	ft_check_colec(t_img_p *p_map)
{
	int		i;
	int		n_visib;

	i = -1;
	n_visib = 0;
	while (++i < p_map->p_items.size_cols)
	{
		if ((p_map->p_items.cols[i].x - 1) * PIXEL + INVADE <= p_map->x
			&& (p_map->p_items.cols[i].x + 1) * PIXEL - INVADE >= p_map->x
			&& (p_map->p_items.cols[i].y - 1) * PIXEL + INVADE <= p_map->y
			&& (p_map->p_items.cols[i].y + 1) * PIXEL - INVADE >= p_map->y)
			p_map->p_items.cols[i].visib = 0;
		if (p_map->p_items.cols[i].visib)
			n_visib++;
	}
	if (n_visib == 0)
		p_map->open = 1;
}

/**
 * @brief Pinta los objetos del juego excepto el jugador
 * si has cogido el coleccionable abre la puerta y desaparece el coleccionable
 * @param p_map struck con variables inicializadas
 */
void	ft_draw_items(t_img_p *p_map)
{
	int	i;

	i = -1;
	ft_check_colec(p_map);
	while (p_map->p_items.size_cols > ++i)
	{
		if (p_map->p_items.cols[i].visib)
			mlx_draw_texture(p_map->img, p_map->textures.img_col,
				p_map->p_items.cols[i].x * PIXEL,
				p_map->p_items.cols[i].y * PIXEL);
	}
	mlx_draw_texture(p_map->img, p_map->textures.img_bad, p_map->p_items.x_bad,
		p_map->p_items.y_bad);
	if (p_map->open)
	{
		mlx_draw_texture(p_map->img, p_map->textures.img_open_door,
			p_map->p_items.x_door,
			p_map->p_items.y_door);
	}
	else
	{
		mlx_draw_texture(p_map->img, p_map->textures.img_close_door,
			p_map->p_items.x_door,
			p_map->p_items.y_door);
	}
}

/**
 * @brief carga las funciones necesarias para el desarrollo del juego
 * 
 * @param map recible el string con la ruta del mapa
 * @param p_map recibe la estructura con las variables inicializadas
 */
void	ft_generate_window(char *map, t_img_p *p_map)
{
	ft_save_imgs(&p_map->textures);
	check_map(p_map);
	p_map->mlx = mlx_init(PIXEL * p_map->width, PIXEL * p_map->height,
			"So_long", 1);
	p_map->img = mlx_new_image(p_map->mlx, PIXEL * p_map->width,
			PIXEL * p_map->height);
	if (!p_map->img)
		ft_error("Error al cargar la ventana\n");
	mlx_key_hook(p_map->mlx, move_and_perspective_p, p_map);
	mlx_image_to_window(p_map->mlx, p_map->img, 0, 0);
	read_and_draw_map(map, p_map->textures, p_map);
	mlx_draw_texture(p_map->img, p_map->textures.img_front, p_map->x, p_map->y);
	ft_draw_items(p_map);
	mlx_loop(p_map->mlx);
	free(p_map->p_items.cols);
	ft_delete_map(p_map);
	ft_delete_imgs(&p_map->textures);
	mlx_terminate(p_map->mlx);
}
