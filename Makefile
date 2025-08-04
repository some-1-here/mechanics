CC = gcc
CFLAGS = -Iinclude -Wall
LDFLAGS = -lm

SRC = src/Pully.c src/main_pully.c

OUT = pully_app

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

all: $(OUT)

clean:
	rm -f $(OUT)
