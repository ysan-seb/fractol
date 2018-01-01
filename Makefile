# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 07:19:36 by ysan-seb          #+#    #+#              #
#    Updated: 2017/12/27 15:41:50 by ysan-seb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# google : -iquote 

NAME	=	fractol

SRC_PATH = src/

SRCS 	= 	$(SRC_PATH)main.c \
			$(SRC_PATH)ft_data_init.c \
			$(SRC_PATH)ft_keyboard_event.c \
			$(SRC_PATH)ft_mouse_event.c \
			$(SRC_PATH)ft_mouse_over.c \
			$(SRC_PATH)ft_julia.c \
			$(SRC_PATH)ft_mandelbrot.c \
			$(SRC_PATH)ft_sequence.c \
			$(SRC_PATH)ft_quit.c \
			$(SRC_PATH)ft_pixel_put.c \
			$(SRC_PATH)ft_str_color.c

OBJS = $(SRCS:.c=.o)

CC	=	gcc

CFLAGS	= -Wall -Werror -Wextra 

DEBUG = -g -fsanatize=address

MFLAGS = -L/usr/local/lib/ -I/usr/local/include -lm -lmlx -framework OpenGL -framework AppKit

HEADER = -I./

LIBFT = ./libft/libft.a

LIBMLX = /usr/local/lib/libmlx.a

RM	=	rm -rf

all	: lib $(NAME)

lib :
	@make -C libft/

$(NAME)	:	$(OBJS) 
	$(CC) -o $(NAME) $(OBJS) $(HEADER) $(MFLAGS) $(LIBFT) $(LIBMLX)

%.o: %.c inc/fractol.h
	gcc -c -Wall -Wextra -Werror -o $@ -c $< -I./inc 

clean	:
	@make -C libft/ clean
	$(RM) $(OBJS)

fclean: clean
	@make -C libft/ fclean
	$(RM) $(NAME)

re	:	fclean
	make

.PHONY: all lib clean fclean re
