# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 09:17:57 by jlimones          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2023/01/13 09:51:18 by jlimones         ###   ########.fr        #
=======
#    Updated: 2023/02/04 11:10:05 by jlimones         ###   ########.fr        #
>>>>>>> e397e74c1f03a57c09a84d30986a2c1e6cd51e62
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = libft/libft.a
FLAGS = -Wall -Werror -Wextra
LIB = -lglfw -L /sgoinfre/goinfre/Perso/jlimones/homebrew/Cellar/glfw/3.3.8/lib
<<<<<<< HEAD
#LIB = -lglfw -L /usr/local/Cellar/glfw/3.3.8/lib
=======
# LIB = -lglfw -L /jlimones/homebrew/Cellar/glfw/3.3.8/lib
>>>>>>> e397e74c1f03a57c09a84d30986a2c1e6cd51e62
MLX = MLX42/libmlx42.a
SRC = 	src/so_long.c \
		src/check_map.c \
		src/load_delete_img.c \
		src/draw_map.c \
		src/generate_window.c \
		src/position_item.c \
		src/read_map.c \
		src/error.c \
		src/free_road.c \
		src/move_pj.c


all: $(NAME)

$(NAME): $(SRC)
	@make -C libft
	@make -C MLX42
	gcc -o $(NAME) $(FLAGS) $(SRC) $(LIB) $(MLX) $(LIBFT)

skiperror:
	gcc -o $(NAME) $(SRC) -g $(LIB)

clean:
	@make clean -C libft
	@make clean -C MLX42

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft
	@make fclean -C MLX42
	

re: fclean all