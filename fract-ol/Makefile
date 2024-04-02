# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 22:16:17 by guillaumeco       #+#    #+#              #
#    Updated: 2024/03/19 13:13:32 by guillaumeco      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MLX = libmlx.a -framework OpenGL -framework AppKit

INCLUDE = -I includes

SOURCES = events \
		init \
		main \
		math_utils \
		render \
		string_utils

SRCS = $(addsuffix .c, $(SOURCES)) 
OBJS = $(addsuffix .o, $(SOURCES))

GREEN = \033[0;32m
GREEN_BOLD = \033[1;32m
RED = \033[0;31m
RED_BOLD = \033[1;31m
MAGENTA = \033[0;35m
BLUE = \033[0;34m
ORANGE = \033[0;38;5;214m
YELLOW = \033[0;33m
CLIGNOT = \033[5m
WHITE_BG = \033[47m
CLOSE = \033[0m
PINK = \033[1;35m
BLACK = \033[0;30m


TOTAL_FILES     := $(words $(SRCS))
CURRENT_FILE     := 0

define progress_bar
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
    @printf "\r$(BLACK)Compiling Fract_ol... ⌛⌛⌛|%-$(TOTAL_FILES)s| %d/%d $(NC)" $$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "███"; done) $(CURRENT_FILE) $(TOTAL_FILES)
    @if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo "$(BLACK)\n\nFract_ol Tu peux lancer chef 👌\n$(CLOSE)"; fi
endef

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(MLX) $(INCLUDE) $(SRCS) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	$(call progress_bar)
	
clean :
	@$(RM) -r $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re	