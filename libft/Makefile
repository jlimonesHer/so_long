# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 12:35:12 by jlimones          #+#    #+#              #
#    Updated: 2022/12/19 17:44:21 by jlimones         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strlcat.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strncmp.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strnstr.c \
	  ft_atoi.c \
	  ft_calloc.c \
	  ft_strdup.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_split.c \
	  ft_itoa.c \
	  ft_strmapi.c \
	  ft_striteri.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c

OBJ_GNL = GNL/get_next_line.o \
		  GNL/get_next_line_utils.o

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a


BONUS = ft_lstnew_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \


HEAD = libft.h
OBJ = $(SRC:.c=.o)
OBJECTSBONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ft_printf
	@make -C GNL
	@cp ft_printf/libftprintf.a $(NAME)
	ar crs $(NAME) $(OBJ) $(OBJ_GNL)
	
%.o: %.c $(HEAD)
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJECTSBONUS)
	@make clean -C ft_printf
	@make clean -C GNL

fclean: clean
	rm -f $(NAME)
	@make fclean -C ft_printf
	@make fclean -C GNL

re: fclean all

	
bonus: $(OBJ) $(OBJECTSBONUS)
		ar crs $(NAME) $(OBJ) $(OBJECTSBONUS)

.PHONY: all, clean, fclean, re, bonus