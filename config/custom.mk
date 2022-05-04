# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    custom.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 13:12:38 by youkim            #+#    #+#              #
#    Updated: 2022/05/04 13:12:39 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

run: all
	@echo 🗺️ running map/valid.cub
	@./$(NAME) map/valid.cub

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
