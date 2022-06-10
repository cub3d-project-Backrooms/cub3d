# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    packages.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkim <tkim@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 13:12:23 by youkim            #+#    #+#              #
#    Updated: 2022/06/10 13:37:27 by tkim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# @Packages
PKGS = renderer raycast engine parser

rendererV = camera image init minimap draw sprite load_tex deinit util\
			dda__dist dda__step
raycastV = floor wall raycast texture
engineV = animation door collision init keyinput movement movement_impl\
		run
parserV = map check__parser check__map__format check__cubid parser\
		check__cubfile cubid map__raw fluidfill check__map__index\
		sprite rgb check__map world

# Macro
SRC_DIR = src/
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)V),\
			$(SRC_DIR)$(pkg)/$(file).c\
		)\
	) $(SRC_DIR)/main.c include/$(UNAME)/platform__hook.c
endef

# Sources & Objects
SRC = $(call choose_modules, $(PKGS))
OBJ = $(SRC:%.c=%.o)