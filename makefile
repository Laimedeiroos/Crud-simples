CC=cc
CFLAGS=-o crud
SOURCES=main.c user.c
HEADERS=user.h

all:
	@$(CC) $(SOURCES) $(CFLAGS)

clean:
	@rm -f crud users.txt
