# Partially inspired from
# https://github.com/mcinglis/c-style/blob/master/license.md

EXECUTABLE=main
SOURCES=$(wildcard *.c)
OBJECTS=$(subst .c,.o,$(SOURCES))

# Provide debug symbols, optimize for debugging
CFLAGS += -g -Og

# Compile with proper warnings
CFLAGS += -Wall -Wextra -Wpedantic \
          -Wformat=2 -Wno-unused-parameter -Wshadow \
          -Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
          -Wredundant-decls -Wnested-externs -Wmissing-include-dirs

# GCC warnings that Clang doesn't provide:
ifeq ($(CC),gcc)
    CFLAGS += -Wjump-misses-init -Wlogical-op
endif

# Use Sarkozy-era C rather than Mitterrand-era C
CFLAGS += -std=c11

# Uncomment for production build
# CFLAGS += -Werror

# Always rebuild
# the targets
# 'all',
# and 'clean'.
.PHONY: all clean

# Default behavior:
# take all .c files
# in current directory
# and turn them
# into one executable
# named main.
all: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXECUTABLE) $^

# Remove
# all .o files
# and main.
clean:
	-rm -f $(EXECUTABLE) $(OBJECTS)
