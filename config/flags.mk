CC     := clang
CFLAGS = -Wall -Wextra -Werror -std=c99
CFLAGS += -g -fsanitize=address -fno-omit-frame-pointer
# CFLAGS += -O3 -Ofast
