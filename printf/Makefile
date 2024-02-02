# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcools <gcools@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 11:55:33 by gcools            #+#    #+#              #
#    Updated: 2023/12/12 14:47:26 by gcools           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDE = includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
SRCS_DIR = srcs/

SOURCES = ft_num_to_hex_return ft_num_to_hex_up_return ft_printf ft_putchar_return ft_putnbr_hex_return ft_putnbr_pos_return ft_putnbr_return ft_putstr_return ft_intlen_original ft_intlen_hex ft_intlen_pos

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SOURCES))) 
OBJS = $(addsuffix .o, $(SOURCES))

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	cp libft/libft.a .
	mv libft.a libftprintf.a
	$(AR) $(NAME) $(OBJS)

%.o : $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
clean :
	rm -rf $(OBJS)
	make clean -C libft

fclean : clean
	rm -f $(NAME)
	make fclean -C libft
	rm -f $(SRCS_DIR)libft.a

re : fclean all

.PHONY : all clean fclean re
