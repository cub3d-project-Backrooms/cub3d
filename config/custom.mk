run: all
	./$(NAME) map/square.cub
# ./$(NAME) asset/map/mandatory.cub

lclean:
	@rm -f $(OBJ)
	@echo "🗑 cleaned $(NAME)'s object files"

lfclean: lclean
	@rm -f $(NAME)
	@echo 🗑 cleaned $(NAME)

le: lclean all

docs:
	@set -e;\
		for p in $(PKGS); do\
			hgen -I include/$$p.h src/$$p & \
		done
	@make -C $(LIBFT_DIR) docs
# 1> /dev/null
