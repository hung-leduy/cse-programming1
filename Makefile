# Biên dịch toàn bộ ví dụ:   make
# Xoá file đã biên dịch:     make clean
#
# - Thư mục có Makefile riêng (chương trình nhiều file): gọi make trong thư mục đó
# - Các file .c còn lại: mỗi file là một chương trình độc lập

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
