NAME     := cub3d.out


CC := clang\
CFLAGS   := -Wall -Wextra -Werror -std=c99	\
						-I include -I include/types			\
						-g3

LIBFT := $(LIB_PATH)/libscarf/libft.a

INC := -I$(LIB_PATH) -I include/ -I include/types \
       -I ../lib/libscarf/include/ -I ../lib/libscarf/include/types/

LIB := -L$(LIB_PATH)/mlx_linux -L$(LIB_PATH)/libscarf \
       -lmlx -lft -lXext -lX11 -lm

include config/os_dependancy.mk
include config/packages.mk


PKGS = engine raycast data

SRC = $(wildcard src/**/*.c) src/main.c
OBJ = $(SRC:.c=.o)

# Mandatory Rules
.PHONY: all clean fclean re

%.o: %.c
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(INC) $(CFLAGS) $^ $(LIB) -o $@
	@echo 🚪 compiled with flag $(CFLAGS)

$(LIBFT):
	make -C $(LIB_PATH)/libscarf/

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "cleaned $(NAME)'s object files"

fclean: clean
	@rm -f $(NAME)
	@echo 🗑 cleaned $(NAME)

re: fclean all

# Custom Rules
run:
	./$(NAME)

docs:
	@set -e;\
		for p in $(PKGS); do\
			hgen -I include/$$p.h src/$$p ;\
		done

#1> /dev/null;\
