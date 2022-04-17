run: docs all
	./$(NAME)

docs:
	@set -e;\
		for p in $(PKGS); do\
			hgen -I include/$$p.h src/$$p 1> /dev/null &\
		done
	@make -C $(LIBFT_DIR) docs &
