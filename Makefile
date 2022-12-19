# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 09:17:57 by jlimones          #+#    #+#              #
#    Updated: 2022/12/19 12:32:34 by jlimones         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = libft/libft.a
FLAGS = -Wall -Werror -Wextra
LIB = -lglfw -L /sgoinfre/goinfre/Perso/jlimones/homebrew/Cellar/glfw/3.3.8/lib
MLX = MLX42/libmlx42.a
SRC = 	src/so_long.c \
		src/error_control.c \
		src/get_map.c


all: $(NAME)

$(NAME): $(SRC)
	@make -C libft
	@make -C MLX42
	gcc -o $(NAME) $(SRC) $(LIB) $(MLX) $(LIBFT)

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