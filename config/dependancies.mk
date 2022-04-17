# MinilibX
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
#   $(info 🍏)
	MLX_DIR   := lib/mlx
	LIBMLX    := $(MLX_DIR)/libmlx.dylib
	LIB       += -lmlx -framework OpenGL -framework Appkit
	CFLAGS    += -I lib/mlx_mac -I include/mac/
else ifeq ($(UNAME), Linux)
#    $(info 🐧)
	MLX_DIR   := lib/mlx_linux
	LIBMLX    := $(MLX_DIR)/libmlx.a
	LIB       += -L $(MLX_DIR) -lXext -lX11 -lm -lmlx
	CFLAGS    += -I $(MLX_DIR) -I include/linux/
else
	$(error "Cannot support $(UNAME)!")
endif


# Libft
LIBFT_DIR := lib/libscarf
LIBFT := $(LIBFT_DIR)/libft.a
LIB += -L $(LIBFT_DIR) -lft
CFLAGS += -I $(LIBFT_DIR)/include/ \
          -I $(LIBFT_DIR)/include/types/

# Dependencies
DEPENDENCIES = $(LIBFT) $(LIBMLX)

