CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = program
SOURCES = main.c arrays.c functions.c
OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q *.o $(TARGET).exe 2>nul || true

.PHONY: clean 