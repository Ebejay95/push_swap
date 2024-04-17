# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 11:02:33 by jeberle           #+#    #+#              #
#    Updated: 2024/04/17 11:22:01 by jeberle          ###   ########.fr        #
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
	@git submodule update --init --recursive --remote
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all