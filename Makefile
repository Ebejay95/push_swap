# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 11:02:33 by jeberle           #+#    #+#              #
#    Updated: 2024/05/04 22:29:03 by jonathanebe      ###   ########.fr        #
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

SUCCESS := \n$(RED)\
████████████████████████████████████████████████████████████████████████$(X)\n\
$(X)\n\
███████  █     █  ███████  █     █    ███████  █     █  ███████  ███████$(X)\n\
█     █  █     █  █        █     █    █        █     █  █     █  █     █$(X)\n\
███████  █     █  ███████  ███████    ███████  █  █  █  ███████  ███████$(X)\n\
█        █     █        █  █     █          █  █ █ █ █  █     █  █      $(X)\n\
█        ███████  ███████  █     █    ███████  ██   ██  █     █  █      $(X)\n\
$(X)\n\
$(RED)████████████████████████████████████████████████████████████████████████$(X)\n\


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
DEPFLAGS=-MMD -MP

#------------------------------------------------------------------------------#
#--------------                        DIR                        -------------#
#------------------------------------------------------------------------------#

OBJ_DIR := ./obj
DEP_DIR := $(OBJ_DIR)/.deps
INC_DIRS := .
SRC_DIRS := project shared tester

vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIRS)
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
push_swap.c

SHARED_SRCS= \
analyzers.c \
analyzers2.c \
costs_helpers.c \
costs.c \
helpers.c \
input.c \
operations.c \
operations2.c \
operations3.c \
operationshelper.c \
psu_handling.c \
shifters.c \
sort.c

TEST_SRCS=checker.c

#------------------------------------------------------------------------------#
#--------------                      OBJECTS                      -------------#
#------------------------------------------------------------------------------#

OBJECTS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
SHARED_OBJECTS := $(addprefix $(OBJ_DIR)/, $(SHARED_SRCS:%.c=%.o))
TEST_OBJECTS := $(addprefix $(OBJ_DIR)/, $(TEST_SRCS:%.c=%.o))

#------------------------------------------------------------------------------#
#--------------                      COMPILE                      -------------#
#------------------------------------------------------------------------------#

.PHONY: all clean fclean re libft

all: $(LIBFT_LIB) $(NAME)

bonus: $(TESTERNAME) $(NAME)

-include $(SHARED_OBJECTS:.o=.d)
-include $(TEST_OBJECTS:.o=.d)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

$(TESTOBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

$(TESTERNAME): $(LIBFT_LIB) $(SHARED_OBJECTS) $(TEST_OBJECTS)
	@$(CC) $(LIBFTFLAGS) -o $@ $^
	@echo "\033[32mSUCCESS: push_swap checker\033[0m"

$(LIBFT_LIB):
	@git submodule update --init --recursive --remote > /dev/null 2>&1
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJECTS) $(SHARED_OBJECTS)
	@$(CC) $(LIBFTFLAGS) -o $@ $^
	@echo "$(GREEN)SUCCESS:$(X)\n$(SUCCESS)"

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\033[31mobjects deleted\033[0m"

fclean: clean
	@rm -f $(NAME) $(TESTERNAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\033[31mpush_swap deleted\033[0m"

re: fclean all
