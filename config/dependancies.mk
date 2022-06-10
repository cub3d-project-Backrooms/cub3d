# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 13:12:28 by youkim            #+#    #+#              #
#    Updated: 2022/05/04 14:09:48 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MinilibX
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	ENV_STR   := 🍏
	MLX_DIR   := lib/mlx_mac
	LIBMLX    := $(MLX_DIR)/libmlx.dylib
	LIB       += -L. -lmlx -framework Metal -framework MetalKit
else ifeq ($(UNAME), Linux)
	ENV_STR   := 🐧
	MLX_DIR   := lib/mlx_linux
	LIBMLX    := $(MLX_DIR)/libmlx.a
	LIB       += -L $(MLX_DIR) -lXext -lX11 -lm -lmlx
else
	$(error "Cannot support $(UNAME)!")
endif
CFLAGS += -I $(MLX_DIR) -I include/$(UNAME)/

# Libft
LIBFT_DIR := lib/libscarf
LIBFT := $(LIBFT_DIR)/libft.a
LIB += -L $(LIBFT_DIR) -lft
CFLAGS += -I $(LIBFT_DIR)/include/

# Dependencies
DEPENDENCIES = $(LIBFT) $(LIBMLX)

