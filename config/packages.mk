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
PKGS = renderer engine parser

rendererV = raycast_tool raycast_floor raycast_texture \
			camera image init minimap draw\
			raycast load_tex raycast_wall deinit dda__dist dda__step
engineV = init keyinput movement movement2 run collision door
parserV = map check__parser check__cubid parser check__cubfile cubid\
		map__raw fluidfill check__map__index rgb check__map check__map2

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
