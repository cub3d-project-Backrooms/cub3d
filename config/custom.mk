run: all
	./$(NAME)

# docs:
# 	@set -e;\
# 		for p in $(PKGS); do\
# 			hgen -I include/$$p.h src/$$p;\
# 		done
# 	@make -C $(LIBFT_DIR) docs
# 1> /dev/null
