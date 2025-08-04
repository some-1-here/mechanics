CC = gcc
CFLAGS = -Iinclude -Wall
LDFLAGS = -lm

PULLY_SRC = src/Pully.c src/main_pully.c
PULLY_OUT = pully_app

TRAILER_SRC = src/Trailer.c src/main_trailer.c
TRAILER_OUT = trailer_app

all: $(PULLY_OUT) $(TRAILER_OUT)

$(PULLY_OUT): $(PULLY_SRC)
	$(CC) $(CFLAGS) $(PULLY_SRC) -o $(PULLY_OUT) $(LDFLAGS)

$(TRAILER_OUT): $(TRAILER_SRC)
	$(CC) $(CFLAGS) $(TRAILER_SRC) -o $(TRAILER_OUT) $(LDFLAGS)

clean:
	rm -f $(PULLY_OUT) $(TRAILER_OUT)
