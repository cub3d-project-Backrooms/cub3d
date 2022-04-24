run: all
	./$(NAME) map/valid_mandatory.cub

try: all
	@set -e ;\
		MAP=$$(python -c "from random import shuffle;\
			from pathlib import Path;m=list(Path('map').iterdir());\
			shuffle(m);print(m.pop())");\
		echo 🗺️ running $$MAP;\
		./$(NAME) $$MAP
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
