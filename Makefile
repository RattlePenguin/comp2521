# To use this Makefile, run:
# make -f (PATH TO MAKEFILE) file=(FILE TO COMPILE)

# 1. Directories
ROOT_DIR := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
HEADER_DIR := $(ROOT_DIR)/data-structures
LIB_NAME := libutils.a

# 2. Find all utility source files and convert to .o object files
UTIL_SOURCES := $(shell find $(HEADER_DIR) -name "*.c")
UTIL_OBJECTS := $(UTIL_SOURCES:.c=.o)

# 3. Find all subdirectories for includes (e.g., data-structures/graphs, data-structures/trees)
INCLUDE_FLAGS := -I$(HEADER_DIR) $(shell find $(HEADER_DIR) -type d | sed 's/^/-I/')

# 4. Settings
file ?= main.c
output = $(basename $(file))
CC = gcc
CFLAGS = -ggdb -pedantic-errors -Wall -Wextra -Werror -Wconversion -Wsign-conversion $(INCLUDE_FLAGS)
AR = ar rcs

# --- Targets ---

all: $(output)

# Step A: Create the static library (.a) from the utility .o files
$(LIB_NAME): $(UTIL_OBJECTS)
	@echo "Archiving $(LIB_NAME)..."
	$(AR) $@ $^
	mv $(LIB_NAME) $(HEADER_DIR)

# Step B: Compile individual .c files in the header dir into .o files
# Only happens if the .c file was modified
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Step C: Link your local file with the static library
$(output): $(file) $(LIB_NAME)
	@echo "Linking $(output)..."
	$(CC) $(CFLAGS) $(file) -L$(HEADER_DIR) -l:$(LIB_NAME) -o $(output)

clean:
	rm -f $(output) $(LIB_NAME)
	find $(HEADER_DIR) -name "*.o" -delete

.PHONY: all clean
