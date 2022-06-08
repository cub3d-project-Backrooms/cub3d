# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mandatory.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 13:12:20 by youkim            #+#    #+#              #
#    Updated: 2022/05/04 14:03:02 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS += -I include/
ifdef BONUS
	CFLAGS += -D BONUS=1
endif

.PHONY: all bonus clean fclean re

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(DEPENDENCIES)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@
	@echo 🚪 compiled $@ for $(ENV_STR)

all: $(NAME)

bonus:
	make BONUS=true

clean:
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)
	@if [[ $(UNAME) == "Darwin" && -f $(notdir $(LIBMLX)) ]]; then\
		echo "rm $(notdir $(LIBMLX))" ;\
		rm -f $(notdir $(LIBMLX)) ;\
	fi
	@echo "🗑 cleaned $(NAME)'s object files and libraries"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo 🗑 cleaned $(NAME)

re: fclean all

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBMLX):
	make -C $(MLX_DIR)
	cp $(LIBMLX) ./
