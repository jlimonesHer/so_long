# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 09:17:57 by jlimones          #+#    #+#              #
#    Updated: 2023/01/13 15:54:31 by jlimones         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = libft/libft.a
FLAGS = -Wall -Werror -Wextra
LIB = -lglfw -L /sgoinfre/goinfre/Perso/jlimones/homebrew/Cellar/glfw/3.3.8/lib
#LIB = -lglfw -L /usr/local/Cellar/glfw/3.3.8/lib
MLX = MLX42/libmlx42.a
SRC = 	src/so_long.c \
		src/check_map.c \
		src/load_delete_img.c \
		src/draw_map.c \
		src/generate_window.c \
		src/position_item.c \
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