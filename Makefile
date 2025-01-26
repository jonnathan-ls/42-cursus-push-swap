# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile.c                                         :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2025/01/12 15:45:31 by                   #+#    #+#             #
#   Updated: 2025/01/25 17:14:51 by jlacerda         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

SRCS_DIR = ./sources
OBJS_DIR = ./objects
INCLUDES_DIR = ./includes
LIBS_DIR = ./libraries

SOURCES = \
	$(SRCS_DIR)/main.c \
	$(SRCS_DIR)/swap.c \
	$(SRCS_DIR)/push.c \
	$(SRCS_DIR)/utils.c \
	$(SRCS_DIR)/stack.c \
	$(SRCS_DIR)/finder.c \
	$(SRCS_DIR)/pusher.c \
	$(SRCS_DIR)/sorter.c \
	$(SRCS_DIR)/validator.c \
	$(SRCS_DIR)/rotate_up.c \
	$(SRCS_DIR)/rotate_down.c \
	$(SRCS_DIR)/initializer.c \

BONUS_SOURCES = \
$(SRCS_DIR)/swap.c \
	$(SRCS_DIR)/push.c \
	$(SRCS_DIR)/utils.c \
	$(SRCS_DIR)/stack.c \
	$(SRCS_DIR)/finder.c \
	$(SRCS_DIR)/pusher.c \
	$(SRCS_DIR)/sorter.c \
	$(SRCS_DIR)/validator.c \
	$(SRCS_DIR)/rotate_up.c \
	$(SRCS_DIR)/rotate_down.c \
	$(SRCS_DIR)/initializer.c \
	$(SRCS_DIR)/checker_bonus.c \

OBJECTS = $(SOURCES:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
BONUS_OBJECTS = $(BONUS_SOURCES:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

LIBFT_DIR = $(LIBS_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INCLUDES_DIR) -I$(LIBFT_DIR)/includes

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $@

$(BONUS_NAME): $(BONUS_OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT) $(if $(PRINT_OP),-D PRINT_OP=$(PRINT_OP)) -o $@

bonus: $(BONUS_NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(if $(PRINT_OP),-D PRINT_OP=$(PRINT_OP)) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -f $(BONUS_OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus