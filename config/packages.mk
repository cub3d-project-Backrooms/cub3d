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
PKGS = engine parser raycast renderer

engineV = collision door init keyinput movement movement_impl run
parserV = check__cubfile check__cubid check__map check__map2\
		check__map__index check__parser cubid fluidfill map map__raw\
		parser rgb
raycastV = floor raycast texture wall
rendererV = camera dda__dist dda__step deinit draw image init load_tex\
			minimap util

# Macro
SRC_DIR = src/
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)V),\
			$(SRC_DIR)$(pkg)/$(file).c\
		)\
	) $(SRC_DIR)/main.c
endef

# Sources & Objects
SRC = $(call choose_modules, $(PKGS))
OBJ = $(SRC:%.c=%.o)