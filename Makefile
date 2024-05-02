# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 11:02:33 by jeberle           #+#    #+#              #
#    Updated: 2024/05/02 22:30:09 by jonathanebe      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
TESTERNAME=checker

LIBFT_DIR=libft
LIBFT=libft.a
LIBFT_LIB=$(LIBFT_DIR)/$(LIBFT)

CC=cc
CFLAGS=-Wall -Wextra -Werror -fsanitize=address -g
LFLAGS=-L$(LIBFT_DIR) -lft

SRCS= \
./project/analyzers.c \
./project/analyzers2.c \
./project/costs_helpers.c \
./project/costs.c \
./project/helpers.c \
./project/input.c \
./project/push_swap.c \
./project/operations.c \
./project/operations2.c \
./project/operations3.c \
./project/operationshelper.c \
./project/psu_handling.c \
./project/shifters.c \
./project/sort.c

TESTERSRC=tester/checker.c

OBJ_DIR=obj/
TESTOBJ_DIR=$(OBJ_DIR)tester/
OBJECTS=$(SRCS:%.c=$(OBJ_DIR)%.o)
TESTEROBJECTS=$(TESTERSRC:%.c=$(TESTOBJ_DIR)%.o)

.PHONY: all clean fclean re libft checker bonus

all: $(LIBFT_LIB) $(NAME)

bonus: $(LIBFT_LIB) $(NAME) $(TESTERNAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(TESTOBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(TESTERNAME): $(TESTEROBJECTS)
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^
	@echo "\033[32mSUCCESS: push_swap checker\033[0m"

$(LIBFT_LIB):
	@git submodule update --init --recursive --remote > /dev/null 2>&1
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^
	@echo "\033[32mSUCCESS: push_swap\033[0m"

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\033[31mobjects deleted\033[0m"

fclean: clean
	@rm -f $(NAME) $(TESTERNAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\033[31mpush_swap deleted\033[0m"

re: fclean all