NAME   := cub3d.out

# Flags
CC     := clang
CFLAGS = -g3 -Wall -Wextra -Werror -std=c99

# Packages
include config/packages.mk

# Dependencies
include config/dependancies.mk

# Rules
include config/mandatory.mk
include config/custom.mk

