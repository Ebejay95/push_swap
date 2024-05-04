# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 11:02:33 by jeberle           #+#    #+#              #
#    Updated: 2024/05/04 14:44:32 by jeberle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# VPATH: https://www.gnu.org/software/make/manual/html_node/General-Search.html
# vpath: https://www.gnu.org/software/make/manual/html_node/Selective-Search.html
 make DEBUG=1
#NAME=push_swap
#TESTERNAME=checker
#
#LIBFT_DIR=libft
#LIBFT=libft.a
#LIBFT_LIB=$(LIBFT_DIR)/$(LIBFT)
#
#CC=cc
#CFLAGS=-Wall -Wextra -Werror
##CFLAGS=-Wall -Wextra -Werror -fsanitize=address -g
#LFLAGS=-L$(LIBFT_DIR) -lft
#
#PS_SRCS= \
#./project/push_swap.c
#
#SRCS= \
#./shared/analyzers.c \
#./shared/analyzers2.c \
#./shared/costs_helpers.c \
#./shared/costs.c \
#./shared/helpers.c \
#./shared/input.c \
#./shared/operations.c \
#./shared/operations2.c \
#./shared/operations3.c \
#./shared/operationshelper.c \
#./shared/psu_handling.c \
#./shared/shifters.c \
#./shared/sort.c
#
#TESTERSRC=tester/checker.c
#
#OBJ_DIR=obj/
#TESTOBJ_DIR=$(OBJ_DIR)tester/
#PS_OBJECTS=$(PS_SRCS:%.c=$(OBJ_DIR)%.o)
#OBJECTS=$(SRCS:%.c=$(OBJ_DIR)%.o)
#TESTEROBJECTS=$(TESTERSRC:%.c=$(TESTOBJ_DIR)%.o)
#
#.PHONY: all clean fclean re libft
#
#all: $(LIBFT_LIB) $(NAME)
#
#bonus: $(TESTERNAME) $(NAME)
#
#-include $(OBJECTS:.o=.d)
#-include $(TESTEROBJECTS:.o=.d)
#
#$(OBJ_DIR)%.o: %.c
#	@mkdir -p $(@D)
#	@$(CC) $(CFLAGS) -MMD -c $< -o $@
#
#$(TESTOBJ_DIR)%.o: %.c
#	@mkdir -p $(@D)
#	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@
#
#$(TESTERNAME): $(LIBFT_LIB) $(OBJECTS) $(TESTEROBJECTS)
#	@$(CC) $(LFLAGS) -o $@ $^
#	@echo "\033[32mSUCCESS: push_swap checker\033[0m"
#
#$(LIBFT_LIB):
#	@git submodule update --init --recursive --remote > /dev/null 2>&1
#	@$(MAKE) -C $(LIBFT_DIR)
#
#$(NAME): $(PS_OBJECTS) $(OBJECTS)
#	@$(CC) $(LFLAGS) -o $@ $^
#	@echo "\033[32mSUCCESS: push_swap\033[0m"
#
#clean:
#	@rm -rf $(OBJ_DIR)
#	@$(MAKE) -C $(LIBFT_DIR) clean
#	@echo "\033[31mobjects deleted\033[0m"
#
#fclean: clean
#	@rm -f $(NAME) $(TESTERNAME)
#	@$(MAKE) -C $(LIBFT_DIR) fclean
#	@echo "\033[31mpush_swap deleted\033[0m"
#
#re: fclean all
#