# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 11:34:43 by gcools            #+#    #+#              #
#    Updated: 2024/01/24 17:49:09 by guillaumeco      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server
INCLUDE = -I minitalk.h
PRINTF = printf
CC = cc
CFLAGS = -Wall -Werror -Wextra


SOURCEC = client
SOURCES = server

SRCSS = $(addsuffix .c, $(SOURCES))
OBJSS = $(addsuffix .o, $(SOURCES))

SRCSC = $(addsuffix .c, $(SOURCEC))
OBJSC = $(addsuffix .o, $(SOURCEC))

all : $(NAMEC) $(NAMES)

$(NAMEC) : $(OBJSC)
	@make -C $(PRINTF)
	@$(CC) $(CFLAGS) $(PRINTF)/libftprintf.a $(INCLUDE) -o $(NAMEC) $(SRCSC)

$(NAMES) : $(OBJSS)
	@$(CC) $(CFLAGS) $(PRINTF)/libftprintf.a $(INCLUDE) -o $(NAMES) $(SRCSS)
	
clean : 
	rm -rf $(OBJSC)
	rm -rf $(OBJSS)
	@make clean -C $(PRINTF)


fclean : clean
	rm $(NAMEC)
	rm $(NAMES)
	@make fclean -C $(PRINTF)
