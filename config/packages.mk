# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    packages.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 13:12:23 by youkim            #+#    #+#              #
#    Updated: 2022/05/04 13:12:24 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# @Packages
PKGS = renderer engine parser

rendererV = raycast_tool raycast_floor camera image init minimap draw\
			raycast load_tex raycast_wall deinit dda__dist dda__step
engineV = init keyinput movement run
parserV = map check__parser check__cubid parser check__cubfile cubid\
		map__raw fluidfill check__map__index rgb check__map

# Macro
SRC_DIR = src/
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)V),\
			$(SRC_DIR)/$(pkg)/$(file).c\
		)\
	) $(SRC_DIR)/main.c
endef

# Sources & Objects
SRC = $(call choose_modules, $(PKGS))
OBJ = $(SRC:%.c=%.o)
