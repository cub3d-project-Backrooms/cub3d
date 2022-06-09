# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 13:12:13 by youkim            #+#    #+#              #
#    Updated: 2022/05/04 13:12:14 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   := cub3D
CFLAGS = -Wall -Wextra -Werror -std=c99

# Flags
include config/flags.mk

# Packages
include config/packages.mk

# Dependencies
include config/dependancies.mk

# Rules
include config/mandatory.mk
include config/custom.mk
include config/test.mk
