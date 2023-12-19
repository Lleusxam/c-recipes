# Makefile

# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -Wextra -pedantic

# Source files
SRCS := main.c autores.c receitas.c cardapio.c validacoes.c

# Object files
OBJS := $(SRCS:.c=.o)

# Header files
HDRS := autores.h receitas.h cardapio.h validacoes.h

# Executable name
TARGET := c-recipes

# Windows-specific settings
ifeq ($(OS),Windows_NT)
    RM := del /Q
    TARGET := $(TARGET).exe
else
    RM := rm -f
endif

# Default target
all: $(TARGET)

# Compile object files
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean up object files and executable
clean:
	$(RM) $(OBJS) $(TARGET)
