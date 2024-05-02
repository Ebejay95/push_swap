# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 11:02:33 by jeberle           #+#    #+#              #
#    Updated: 2024/05/02 17:32:51 by jonathanebe      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
NAME=checker

LIBFT_DIR=libft
LIBFT=libft.a
LIBFT_LIB=$(LIBFT_DIR)/$(LIBFT)

CODEDIRS=.
CC=cc
#CC=cc -fsanitize=address -g
CFLAGS= -Wall -Wextra -Werror
DEPFLAGS= -MP -MD
LFLAGS=-L$(LIBFT_DIR) -lft

SRCS= \
./analyzers.c \
./analyzers2.c \
./costs_helpers.c \
./costs.c \
./helpers.c \
./input.c \
./push_swap.c \
./operations.c \
./operations2.c \
./operations3.c \
./operationshelper.c \
./psu_handling.c \
./shifters.c \
./sort.c \

CFILES= $(SRCS)
OBJECTS=$(CFILES:.c=.o)
DEPFILES=push_swap.h

.PHONY:	all clean fclean re libft

all: $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
	@git submodule update --init --recursive --remote > /dev/null 2>&1
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LFLAGS)
	@echo "\033[32mSUCCESS: push_swap\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: 

clean:
	@rm -rf $(OBJECTS) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\033[31mobjects deleted\033[0m"

fclean:
	@rm -rf $(NAME) $(OBJECTS)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\033[31mpush_swap deleted\033[0m"

re: fclean all
