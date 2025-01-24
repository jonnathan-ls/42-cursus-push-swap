NAME = push_swap

SRCS_DIR = ./sources
OBJS_DIR = ./objects
INCLUDES_DIR = ./includes
LIBS_DIR = ./libraries

SOURCES = \
	$(SRCS_DIR)/main.c \
	$(SRCS_DIR)/utils.c \
	$(SRCS_DIR)/sorting.c \
	$(SRCS_DIR)/rotate_up.c \
	$(SRCS_DIR)/rotate_down.c \
	$(SRCS_DIR)/swap.c \
	$(SRCS_DIR)/push.c \

OBJECTS = $(SOURCES:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

LIBFT_DIR = $(LIBS_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a


CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INCLUDES_DIR) -I$(LIBFT_DIR)/includes

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(LDFLAGS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re