# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 11:02:33 by jeberle           #+#    #+#              #
#    Updated: 2024/04/19 08:43:54 by jeberle          ###   ########.fr        #
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

all: $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
	@git submodule update --init --recursive --remote > /dev/null 2>&1
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJECTS)
	@echo "\033[32mSUCCESS: push_swap\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJECTS) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\033[31mobjects deleted\033[0m"

fclean:
	@rm -rf $(NAME) $(OBJECTS)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\033[31mpush_swap deleted\033[0m"

re: fclean all
