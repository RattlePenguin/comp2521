# Get absolute path of root dir and data-structures
ROOT_DIR := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
HEADER_DIR := $(ROOT_DIR)/data-structures
LIB_NAME := libutils.a

# Find all utility source files and convert to object files
UTIL_SOURCES := $(shell find $(HEADER_DIR) -name "*.c")
UTIL_OBJECTS := $(UTIL_SOURCES:.c=.o)

# Find all include paths and prepend -I
INCLUDE_FLAGS := $(shell find $(HEADER_DIR) -type d | sed 's/^/-I/')

# Compiler and flags
CC = gcc
CFLAGS = $(INCLUDE_FLAGS) -ggdb -pedantic-errors -Wall -Wextra -Wconversion -Wsign-conversion -Werror

# Get the name of the file passed via command line (e.g., make file=main.c)
# If no file is provided, it defaults to 'main.c'
file ?= main.c
output = $(basename $(file))

# Standard build target
all: $(output)

# Create the static library (.a) from util (.o) files
$(LIB_NAME): $(UTIL_OBJECTS)
	@echo "Archiving $(LIB_NAME) using ar rcs..."
	ar rcs $@ $^
	mv $(LIB_NAME) $(HEADER_DIR)

# Compile source (.c) files into object (.o) files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(output): $(file) $(LIB_NAME)
	$(CC) $(CFLAGS) $(file) -L$(HEADER_DIR) -l:$(LIB_NAME) -o $(output)

# Clean up the binary
clean:
	rm -f $(output)
	find $(HEADER_DIR) -name "*.o" -delete

.PHONY: all clean
