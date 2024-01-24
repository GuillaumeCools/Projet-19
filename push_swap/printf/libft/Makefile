# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcools <gcools@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 11:34:43 by gcools            #+#    #+#              #
#    Updated: 2023/11/03 13:57:54 by gcools           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE = ../includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

SOURCES = ft_bzero ft_atoi ft_calloc ft_isalnum ft_isalpha \
		  ft_isascii ft_isdigit ft_isprint ft_itoa ft_memchr \
		  ft_memcmp ft_memcpy ft_memmove ft_memset ft_putchar_fd \
		  ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_split ft_strchr \
		  ft_strdup ft_striteri ft_strjoin ft_strlcat ft_strlcpy ft_strlen \
		  ft_strmapi ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr \
		  ft_tolower ft_toupper
		

SRCS = $(addsuffix .c, $(SOURCES)) 
OBJS = $(addsuffix .o, $(SOURCES))

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS) 

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
