# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 09:17:57 by jlimones          #+#    #+#              #
#    Updated: 2022/12/11 19:48:27 by jlimones         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = libft/libft.a
FLAGS = -Wall -Werror -Wextra
SRC = src/so_long_prueba.c \


INC =	src/so_long_prueba.c \

LIB = -L ./libft -lft -L ./mlx -lmlx -lXext -lX11

all: $(NAME)

$(NAME):
	@make -C libft
	@make -C minilibx
	

skiperror:
	gcc -o $(NAME) $(SRC) -g $(LIB)

clean:
	@make clean -C libft
	@make clean -C mlx

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft

re: fclean all