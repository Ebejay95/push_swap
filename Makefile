# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 11:02:33 by jeberle           #+#    #+#              #
#    Updated: 2024/05/04 21:20:22 by jonathanebe      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#--------------                       PRINT                       -------------#
#------------------------------------------------------------------------------#

RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
BLUE := \033[34m
MAGENTA := \033[35m
CYAN := \033[36m
X := \033[0m

INTRO := \n$(RED)\
███████████████████████████████████████████████████████████████$(X)\n\
$(X)\n\
██████  █    █  ██████ █    █    ██████  █    █  ██████  ██████$(X)\n\
█    █  █    █  █      █    █    █       █    █  █    █  █    █$(X)\n\
██████  █    █  ██████ ██████    ██████  █    █  ██████  ██████$(X)\n\
█       █    █       █ █    █         █  █ ██ █  █    █  █     $(X)\n\
█       ██████  ██████ █    █    ██████  ██  ██  █    █  █     $(X)\n\
$(X)\n\
$(RED)███████████████████████████████████████████████████████████████$(X)\n\


#------------------------------------------------------------------------------#
#--------------                      GENERAL                      -------------#
#------------------------------------------------------------------------------#

NAME=push_swap
TESTERNAME=checker

#------------------------------------------------------------------------------#
#--------------                       FLAGS                       -------------#
#------------------------------------------------------------------------------#

CC=cc
CFLAGS=-Wall -Wextra -Werror
ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address -g
endif

#------------------------------------------------------------------------------#
#--------------                        DIR                        -------------#
#------------------------------------------------------------------------------#

OBJ_DIR := ./obj
DEP_DIR := $(OBJ_DIR)/.deps
#INC_DIRS := 
SRC_DIRS := project shared tester

vpath %.c $(SRC_DIRS)
#vpath %.h $(INC_DIRS)
vpath %.d $(DEP_DIR)

#------------------------------------------------------------------------------#
#--------------                        LIBS                       -------------#
#------------------------------------------------------------------------------#

LIBFT_DIR=libft
LIBFT=libft.a
LIBFT_LIB=$(LIBFT_DIR)/$(LIBFT)
LIBFTFLAGS=-L$(LIBFT_DIR) -lft

#------------------------------------------------------------------------------#
#--------------                        SRC                        -------------#
#------------------------------------------------------------------------------#

SRCS= \
./project/push_swap.c

SHARED_SRCS= \
./shared/analyzers.c \
./shared/analyzers2.c \
./shared/costs_helpers.c \
./shared/costs.c \
./shared/helpers.c \
./shared/input.c \
./shared/operations.c \
./shared/operations2.c \
./shared/operations3.c \
./shared/operationshelper.c \
./shared/psu_handling.c \
./shared/shifters.c \
./shared/sort.c

TEST_SRCS=tester/checker.c

#------------------------------------------------------------------------------#
#--------------                      OBJECTS                      -------------#
#------------------------------------------------------------------------------#

OBJECTS=$(SRCS:%.c=$(OBJ_DIR)%.o)
SHARED_OBJECTS=$(SHARED_SRCS:%.c=$(OBJ_DIR)%.o)
TEST_OBJECTS=$(TEST_SRCS:%.c=$(TESTOBJ_DIR)%.o)

#------------------------------------------------------------------------------#
#--------------                      COMPILE                      -------------#
#------------------------------------------------------------------------------#

.PHONY: all clean fclean re libft

all: $(LIBFT_LIB) $(NAME)
	@echo "$(INTRO)";

bonus: $(TESTERNAME) $(NAME)

-include $(SHARED_OBJECTS:.o=.d)
-include $(TEST_OBJECTS:.o=.d)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -c $< -o $@

$(TESTOBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(TESTERNAME): $(LIBFT_LIB) $(SHARED_OBJECTS) $(TEST_OBJECTS)
	@$(CC) $(LIBFTFLAGS) -o $@ $^
	@echo "\033[32mSUCCESS: push_swap checker\033[0m"

$(LIBFT_LIB):
	@git submodule update --init --recursive --remote > /dev/null 2>&1
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJECTS) $(SHARED_OBJECTS)
	@$(CC) $(LIBFTFLAGS) -o $@ $^
	@echo "\033[32mSUCCESS: push_swap\033[0m"

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\033[31mSHARED_OBJECTS deleted\033[0m"

fclean: clean
	@rm -f $(NAME) $(TESTERNAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\033[31mpush_swap deleted\033[0m"

re: fclean all
