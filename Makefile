CC = cc
PUSH_SWAP = push_swap
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = lib/libft

# List of source files
SRCS = src/main.c src/check_utils.c src/push_swap.c src/push.c src/rotate.c \
       src/init_and_free.c \

# List of object files to build
OBJS = $(SRCS:.c=.o)

# Build executable
all: $(LIBFT_DIR)/libft.a $(PUSH_SWAP)

# Build the client executable
$(PUSH_SWAP): $(OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $@

# Build the libft library
$(LIBFT_DIR)/libft.a: $(LIBFT_DIR)/src/*.c
	$(MAKE) -C $(LIBFT_DIR) all

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

# Remove object files and executables
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

# Remove object files, executables, and the libft library
fclean: clean
	$(RM) $(PUSH_SWAP)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild the project from scratch
re: fclean all

.PHONY: all clean fclean re
