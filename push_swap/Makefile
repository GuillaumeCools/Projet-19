# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 11:55:33 by gcools            #+#    #+#              #
#    Updated: 2024/01/25 13:47:01 by guillaumeco      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

#Compiler and CFlags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_PRINTF = printf/libftprintf.a
INCLUDE = -I includes
SRCS_DIR = srcs/

COMMANDS_DIR =	$(SRCS_DIR)commands/push \
				$(SRCS_DIR)commands/rev_rotate \
				$(SRCS_DIR)commands/rotate \
				$(SRCS_DIR)commands/sort_stacks \
				$(SRCS_DIR)commands/sort_three \
				$(SRCS_DIR)commands/swap
				
PUSH_SWAP_DIR =	$(SRCS_DIR)push_swap/init_a_to_b \
				$(SRCS_DIR)push_swap/init_b_to_a \
				$(SRCS_DIR)push_swap/push_swap \
				$(SRCS_DIR)push_swap/split \
				$(SRCS_DIR)push_swap/stack_init \
				$(SRCS_DIR)push_swap/stack_utils \
				$(SRCS_DIR)push_swap/handle_errors
				
SOURCES =	$(COMMANDS_DIR) $(PUSH_SWAP_DIR)

SRCS = $(addsuffix .c, $(SOURCES)) 
OBJS = $(addsuffix .o, $(SOURCES))

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C printf
	@$(CC) $(CFLAGS) $(LIBFT_PRINTF) $(INCLUDE) $(SRCS) -o $(NAME)
	@ECHO "Ready to use !"

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	@$(RM) -r $(OBJS)
	@make clean -C printf

fclean : clean
	@$(RM) $(NAME)
	@make fclean -C printf

re : fclean all

.PHONY : all clean fclean re
