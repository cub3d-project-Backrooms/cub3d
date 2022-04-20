# Packages
PKGS = engine parser renderer

#FIXME: specify packages

SRC = src/

# Macro
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
