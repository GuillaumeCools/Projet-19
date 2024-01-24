# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 11:55:33 by gcools            #+#    #+#              #
#    Updated: 2024/01/24 18:23:01 by guillaumeco      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

#Compiler and CFlags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_PRINTF = printf/libftprintf.a
INCLUDE = includes/
SRCS_DIR = srcs/
OBJS_DIR = objs/

COMMANDS_DIR =	$(SRCS_DIR)commands/push.c \
				$(SRCS_DIR)commands/rev_rotate.c \
				$(SRCS_DIR)commands/rotate.c \
				$(SRCS_DIR)commands/sort_stacks.c \
				$(SRCS_DIR)commands/sort_three \
				$(SRCS_DIR)commands/swap.c
				
PUSH_SWAP_DIR =	$(SRCS_DIR)push_swap/init_a_to_b.c \
				$(SRCS_DIR)push_swap/init_b_to_a.c \
				$(SRCS_DIR)push_swap/push_swap.c \
				$(SRCS_DIR)push_swap/split.c \
				$(SRCS_DIR)push_swap/stack_init.c \
				$(SRCS_DIR)push_swap/stack_utils.c

SRCS =	$(COMMANDS_DIR) $(PUSH_SWAP_DIR)

OBJS =	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

$(LIBFT_PRINTF):
	@make -C ./printf

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT_PRINTF)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT_PRINTF) -o $(NAME)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	@$(RM) -r $(OBJS_DIR)
	@make clean -C printf

fclean : clean
	$(RM) $(NAME)
	@$(RM) $(LIBFT_PRINTF)

re : fclean all

.PHONY : all clean fclean re
