# ===== Target & FLAGS =====
NAME     := libft.a

CC       := clang
CFLAGS   := -g3 -Wall -Wextra -Werror -std=c99 -I include
#-DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address"

AR       := ar -rcs

# ===== @Packages =====
PKGS     := error math string system

#FIXME: specify packages
stringV  := alloc util
errorV   := error
systemV  := alloc dalloc write

# ===== Macros =====
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)V),\
			src/std__$(pkg)/$(file).c\
		)\
	)
endef

# ===== Sources & Objects & Include =====
#FIXME: specify sources
SRC      := $(wildcard src/**/*.c)
# SRC      := $(call choose_modules, $(PKGS))
OBJ      := $(SRC:%.c=%.o)

# ===== Rules =====
.PHONY: all re clean fclean

%.o: %.c
	@echo "  $(WU)$(<F)$(R) -> $(E)$(@F)"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@$(AR) $@ $^
	@echo 🗃️ archived with flag $(CFLAGS)

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "cleaned $(NAME)'s object files"

fclean: clean
	@rm -f $(NAME)
	@echo 🗑 cleaned $(NAME)

re: fclean all

# ===== Custom Rules =====
docs:
	@set -e;\
		for p in $(PKGS); do\
			hgen -I include/std__$$p.h src/std__$$p;\
		done

test_make: docs all
	@$(CC) $(CFLAGS) $(wildcard test/*.c) $(NAME)  -o test/test.out
#-I test/lib/theft/inc -L test/lib/theft/build/ -ltheft
test: test_make
	@./test/test.out

leak: test_make
	@colour-valgrind ./test/test.out
