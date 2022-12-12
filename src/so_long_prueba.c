/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_prueba.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:35:31 by jlimones          #+#    #+#             */
/*   Updated: 2022/12/12 16:26:02 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//https://github.com/S-LucasSerrano/miniLibX_sample/blob/main/README.md

/*Debido a que miniLibX usa Appkit y MX11, debe vincularlos y 
 * agregarlos -lmlx -framework OpenGL -framework AppKitcuando 
 * compila.*/
int	main(void)
{
/* Inicializa la libreria y devuelve un puntero vacio que usaremos despues*/
void	*mlx_pointer;
mlx_pointer = mlx_init();

/**
 * @brief abre una ventana
 * @param mlx_pointer puntero vacio
 * @param whith ancho ventana
 * @param height alto de ventana
 * @param name titulo en la parte superior
 */
void	window = mlx_new_window(mlx_pointer, WIDTH, HEIGHT, name);

/*Estructura para que contengan los datos*/
typedef struct	s_program
{
	void	*mlx_pointer;
	void	*window;
}				t_program;

/**
 * @brief Construct a new mlx loop object
 * bucle infinito para ejecutar el programa.
 */
mlx_loop(mlx_pointer);

/**
 * @brief Construct a new mlx hook object
 * 
 * @param win_ptr puntero a la ventana que detecta el evento
 * @param event codigo del evento
 * @param mask la mask
 * @param f puntero a la funcion que se llamaria cuando se active el evento
 * @param param puntero que se pasa a la funcion f como parametro
 * La funcion f debe tener este prototipo
 */
mlx_hook(void *win_ptr, int event, int mask, int (*f)(), void *param);

/**
 * @brief 
 * 
 * @param param suele ser una estructura y asi le pasamos todos klos datos necesarios
 * @return int (no se usa)
 */
int	hooked_function(void *param);
}
