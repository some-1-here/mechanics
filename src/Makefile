CC = gcc
CFAGS = -Wall -Iinclude -lm
TARGET = bin/pully
SRC = src/main_pully.c src/pully.c

all: $(TARGET)

$(TAGERT): $(SRC)
	@mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)

.PHONY: all clean
