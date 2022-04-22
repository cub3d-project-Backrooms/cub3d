CFLAGS += -I include/
ifdef BONUS
	CFLAGS += -D BONUS=1
endif

.PHONY: all bonus clean fclean re

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(DEPENDENCIES)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@
	@echo 🚪 compiled $@

all: $(NAME)

bonus:
	make BONUS=true

clean:
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)
	@echo "🗑 cleaned $(NAME)'s object files and libraries"

fclean: clean
	@rm -f $(NAME)
	@echo 🗑 cleaned $(NAME)

re: fclean all

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBMLX):
	make -C $(MLX_DIR)
