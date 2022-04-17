NAME   := cub3d.out

# Flags
CC     := clang
CFLAGS = -Wall -Wextra -Werror -std=c99

CFLAGS += -I include/ -I include/types


# Packages
include config/packages.mk

# Dependencies
include config/dependancies.mk

# Rules
include config/mandatory.mk
include config/custom.mk

