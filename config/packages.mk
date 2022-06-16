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
PKGS = renderer parser raycast engine

rendererV = sprite dda__dist util load_tex init dda__step draw image\
			minimap camera deinit
parserV = cubid sprite check__map__format check__cubfile check__map\
		fluidfill world check__map__index rgb map map__raw\
		check__parser check__cubid parser
raycastV = raycast texture floor wall
engineV = door init run animation movement collision movement_impl\
		keyinput

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