# Build all examples:        make
# Remove compiled files:     make clean
#
# - Directories with their own Makefile (multi-file programs): run make in that directory
# - Remaining .c files: each file is a standalone program

CC ?= gcc
CFLAGS ?= -Wall -Wextra -g

MAKE_DIRS := $(patsubst %/Makefile,%,$(wildcard lecture*/*/Makefile))
SOURCES := $(filter-out $(addsuffix /%,$(MAKE_DIRS)),$(wildcard lecture*/*/*.c))
PROGRAMS := $(SOURCES:.c=)

.PHONY: all clean $(MAKE_DIRS)

all: $(PROGRAMS) $(MAKE_DIRS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

$(MAKE_DIRS):
	$(MAKE) -C $@

clean:
	rm -f $(PROGRAMS)
	for d in $(MAKE_DIRS); do $(MAKE) -C $$d clean; done
