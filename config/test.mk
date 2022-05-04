try: all
	@set -e ;\
		MAP=$$(python3 -c "from random import shuffle;\
			from pathlib import Path;m=list(Path('map').iterdir());\
			shuffle(m);print(m.pop())");\
		echo 🗺️ running $$MAP;\
		./$(NAME) $$MAP
# ./$(NAME) asset/map/mandatory.cub

test-map:
	@set -e ;\
		for cub in map/**/*; do\
			printf "🚨 $${cub%.*} -> " ;\
			! ./$(NAME) $$cub;\
		done
	@echo ✅ all invalid maps failed successfully

#./$(NAME) $$cub ;\

norm: norminette
norminette:
	@set -e ;\
		for dir in lib/libscarf src include; do\
			norminette $$dir ;\
			echo ✅ $$dir: OK! ;\
		done
	@echo ✅ norminette passed successfully
