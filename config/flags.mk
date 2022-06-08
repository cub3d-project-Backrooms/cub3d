# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    flags.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 13:12:26 by youkim            #+#    #+#              #
#    Updated: 2022/05/04 14:49:02 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -std=c99

ifdef LEAK
$(info Leak test enabled)
	CC     := \
		SDKROOT=/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/ \
		~/goinfre/clang+llvm-14.0.3-x86_64-apple-darwin/bin/clang
	CFLAGS += -fsanitize=address
else
$(info Normal mode)
	CC    := clang
	CFLAGS += -O3 -Ofast
endif
