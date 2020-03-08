# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hnaji-el <hnaji-el@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 10:20:16 by hnaji-el          #+#    #+#              #
#    Updated: 2020/01/30 13:58:35 by hnaji-el         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	  ft_format.c \
	  ft_minus_func.c \
	  ft_print_ft.c \
	  ft_put_control.c \
	  ft_put_control2.c \
	  ft_zero_func.c \
	  ft_atoi.c \
	  ft_init_struct.c \
	  ft_num_digits.c \
	  ft_put.c \
	  ft_put_control1.c \
	  ft_width_funct.c \

OBJS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
