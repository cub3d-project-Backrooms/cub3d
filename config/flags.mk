# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    flags.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 13:12:26 by youkim            #+#    #+#              #
#    Updated: 2022/05/04 13:13:21 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     := clang
CFLAGS = -Wall -Wextra -Werror -std=c99
# CFLAGS += -g -fsanitize=address -fno-omit-frame-pointer
CFLAGS += -O3 -Ofast
