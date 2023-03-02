# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 12:00:14 by jlimones          #+#    #+#              #
#    Updated: 2022/12/14 12:04:39 by jlimones         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	get_next_line.c\
		get_next_line_utils.c

CFLAGS = -Wall -Wextra -Werror

NAME = libftGNL.a

HEAD = libftGNL.h
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@ar crs $(NAME) $(OBJ)
	
%.o: %.c $(HEAD)
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re