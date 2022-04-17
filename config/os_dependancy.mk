UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
    MLX_DIR   := lib/mlx
    LIBMLX    := $(MLX_DIR)/libmlx.dylib
    LIB       := -lmlx -framework OpenGL -framework Appkit
    INC       += -I include/mac/
else ifeq ($(UNAME), Linux)
    MLX_DIR   := lib/mlx_linux
    LIBMLX    := $(MLX_DIR)/libmlx.a
    LIB       := -lXext -lX11 -lm -lz
    INC       += -I include/linux/
else
	$(error "Cannot support $(UNAME)!")
endif
