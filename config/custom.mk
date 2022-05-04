# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    custom.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 13:12:38 by youkim            #+#    #+#              #
#    Updated: 2022/05/04 14:46:58 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifdef LEAK
	RUN_OPT = \
		ASAN_OPTIONS=detect_leaks=1 \
		LSAN_OPTIONS=suppressions=supp.txt
endif

run: all
	@echo 🗺️ running map/mandatory.cub
	@$(RUN_OPT) ./$(NAME) map/mandatory.cub

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
