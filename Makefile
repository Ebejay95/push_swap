# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 11:02:33 by jeberle           #+#    #+#              #
#    Updated: 2024/04/18 18:10:50 by jeberle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

LIBFT_DIR=libft
LIBFT=libft.a
LIBFT_LIB=$(LIBFT_DIR)/$(LIBFT)

CODEDIRS=.
CC=cc
CFLAGS= -Wall -Wextra -Werror
DEPFLAGS= -MP -MD
LFLAGS= -L$(LIBFT_DIR) -lft

SRCS= \
./push_swap.c \
./operations.c \
./operations2.c \
./put.c \

CFILES= $(SRCS)
OBJECTS=$(CFILES:.c=.o)
DEPFILES=push_swap.h

.PHONY:	all clean fclean re libft

all: precompile $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
	@git submodule update --init --recursive --remote
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJECTS)
	@echo "\033[32mSUCCESS!!\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJECTS) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\033[31mobjects deleted\033[31m"

fclean:
	@rm -rf $(NAME) $(OBJECTS)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\033[31mpush_swap deleted\033[31m"

re: fclean all

precompile:
	@echo "\033[33mmake push_swap\033[0m"