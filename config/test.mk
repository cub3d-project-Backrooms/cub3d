# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 13:12:18 by youkim            #+#    #+#              #
#    Updated: 2022/05/04 14:34:26 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

try: all
	@set -e ;\
		MAP=$$(python3 -c "from random import shuffle;\
			from pathlib import Path;m=list(Path('map').iterdir());\
			shuffle(m);print(m.pop())");\
		echo πΊοΈ running $$MAP;\
		./$(NAME) $$MAP
# ./$(NAME) asset/map/mandatory.cub

test: all
	@for cub in map/invalid/*; do\
		echo "π¨ $${cub%.*}" ;\
		./$(NAME) $$cub;\
		if [[ $$? == 1 ]]; then\
			echo "β $${cub%.*}";\
		else\
			echo "β $${cub%.*}";\
			exit 1;\
		fi;\
		echo ;\
	done
	@echo β all invalid maps failed successfully

#./$(NAME) $$cub ;\

norm: norminette
norminette:
	@set -e ;\
		for dir in lib/libscarf src include; do\
			norminette $$dir ;\
			echo β $$dir: OK! ;\
		done
	@echo β norminette passed successfully
