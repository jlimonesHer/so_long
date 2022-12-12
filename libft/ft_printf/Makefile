# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 10:20:34 by jlimones          #+#    #+#              #
#    Updated: 2022/12/02 14:28:58 by jlimones         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c \
	  ft_check_type.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putnbr_int.c \
	  ft_putnbr_unsigned.c \
	  ft_p_nbr_hex.c \


CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

HEAD = libftprintf.h
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