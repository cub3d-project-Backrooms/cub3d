# @Packages
PKGS = renderer util engine parser

rendererV = raycast_tool raycast_floor camera image init minimap draw\
			raycast load_tex raycast_wall deinit dda__dist dda__step
engineV = init keyinput movement run
parserV = map check__parser check__cubid parser check__cubfile cubid\
		map__raw fluidfill check__map__index rgb check__map

# Macro
SRC = src/
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)V),\
			$(SRC)/$(pkg)/$(file).c\
		)\
	) $(SRC)/main.c
endef

# Sources & Objects
SRC = $(wildcard src/**/*.c) src/main.c
# SRC = $(call choose_modules, $(PKGS))
OBJ = $(SRC:%.c=%.o)