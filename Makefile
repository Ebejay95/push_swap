# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 11:02:33 by jeberle           #+#    #+#              #
#    Updated: 2024/04/30 22:28:31 by jeberle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
TESTERNAME=checker

LIBFT_DIR=libft
LIBFT=libft.a
LIBFT_LIB=$(LIBFT_DIR)/$(LIBFT)

CODEDIRS=.
#CC=cc
CC=cc -fsanitize=address -g
CFLAGS= -Wall -Wextra -Werror
LFLAGS= -L$(LIBFT_DIR) -lft

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

TESTERSRC= \
./checker/checker.c \

OBJ_DIR=obj/
TESTOBJ_DIR=checker_obj/
OBJECTS=$(SRCS:%.c=$(OBJ_DIR)%.o)
TESTEROBJECTS=$(TESTERSRC:%.c=$(TESTOBJ_DIR)%.o)
DEPFILES=push_swap.h

.PHONY:	all clean fclean re libft checker

all: $(LIBFT_LIB) $(NAME)

bonus: $(TESTERNAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(TESTOBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(TESTERNAME): $(TESTEROBJECTS)
	@$(CC) $(CFLAGS) $(LFLAGS) -o $(TESTERNAME) $(TESTEROBJECTS)
	@echo "\033[32mSUCCESS: push_swap checker\033[0m"

$(LIBFT_LIB):
	@git submodule update --init --recursive --remote > /dev/null 2>&1
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJECTS)
#	@$(CC) $(CFLAGS) $(LFLAGS) -fsanitize=address -o $(NAME) $(OBJECTS)
	@$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJECTS)
	@echo "\033[32mSUCCESS: push_swap\033[0m"

clean:
	@rm -rf $(OBJ_DIR)* $(TESTOBJ_DIR)*
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\033[31mobjects deleted\033[0m"

fclean: clean
	@rm -rf $(NAME) $(TESTERNAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\033[31mpush_swap deleted\033[0m"

re: fclean all
