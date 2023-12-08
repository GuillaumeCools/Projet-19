# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcools <gcools@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 11:34:43 by gcools            #+#    #+#              #
#    Updated: 2023/12/08 14:31:13 by gcools           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
INCLUDE = 
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = libft.a

SOURCES =	

SRCS = $(addsuffix .c, $(SOURCES)) 
OBJS = $(addsuffix .o, $(SOURCES))

all : $(NAME)

$(NAME) : $(OBJS) $(LIB)
	$(CC) $(NAME) $(LIB)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(LIB):
	make -C libft
	cp libft/$(LIB) $(LIB)


clean :
	rm -rf $(OBJS)

fclean : clean
	rm -f $(NAME) $(LIB)

re : fclean all

.PHONY : all clean fclean re
