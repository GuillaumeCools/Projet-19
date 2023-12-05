# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcools <gcools@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 11:34:43 by gcools            #+#    #+#              #
#    Updated: 2023/12/05 14:38:43 by gcools           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
INCLUDE = 
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = libft.a
MLX = libmlx.a

SOURCES =	

SRCS = $(addsuffix .c, $(SOURCES)) 
OBJS = $(addsuffix .o, $(SOURCES))

all : $(NAME)

$(NAME) : $(OBJS) $(LIB) $(MLX)
	$(CC) $(NAME) $(LIB) $(MLX) -lm $(OBJS) 

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(LIB):
	make -C libft
	cp libft/$(LIB) $(LIB)

$(MLX):
	make -C mlx
	cp mlx/$(MLX) $(MLX)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -f $(NAME) $(LIB) $(MLX)
	make fclean -C libft
	make clean -C mlx

re : fclean all

.PHONY : all clean fclean re
