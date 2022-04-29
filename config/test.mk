try: all
	@set -e ;\
		MAP=$$(python -c "from random import shuffle;\
			from pathlib import Path;m=list(Path('map').iterdir());\
			shuffle(m);print(m.pop())");\
		echo 🗺️ running $$MAP;\
		./$(NAME) $$MAP
# ./$(NAME) asset/map/mandatory.cub

test-map:
	@set -e ;\
		for cub in map/**/*.cub; do\
			echo 🚨 invalid file $$cub;\
			! ./$(NAME) $$cub;\
		done
	@echo ✅ all invalid maps failed successfully

#./$(NAME) $$cub ;\
