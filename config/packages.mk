# Packages
PKGS = engine raycast graphic

#FIXME: specify packages
engineV  := alloc util
raycastV := error
graphicV := alloc dalloc write

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
