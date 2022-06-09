# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 13:12:46 by youkim            #+#    #+#              #
#    Updated: 2022/05/04 13:13:05 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target & FLAGS
NAME     := libft.a

CC       := clang
CFLAGS   := -Wall -Wextra -Werror -std=c99 -I include #-g3

AR       := ar -rcs

# @Packages
PKGS = error math string system

errorV = panic panic__index panic__value
mathV = check_char check_num math vector vector_mul
stringV = alloc append cmp convert dealloc find find_of index len move\
		slice split strip util
systemV = alloc mem read read__file write

# Macros
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)V),\
			src/std__$(pkg)/$(file).c\
		)\
	)
endef

# Sources & Objects & Include
SRC      := $(call choose_modules, $(PKGS))
OBJ      := $(SRC:%.c=%.o)

# Rules
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

# Custom
docs:
	@set -e;\
		for p in $(PKGS); do\
			hgen -I include/std__$$p.h src/std__$$p;\
		done
