# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 11:02:33 by jeberle           #+#    #+#              #
#    Updated: 2024/04/16 19:32:10 by jonathanebe      ###   ########.fr        #
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
./listhelpers.c \
./debug.c \

CFILES= $(SRCS)
OBJECTS=$(CFILES:.c=.o)
DEPFILES=push_swap.h

.PHONY:	all clean fclean re libft

all: $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
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