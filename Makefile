CC = gcc
CFLAGS = -Wall
exec = ./bin/main_1 ./bin/main_2 ./bin/main_3

.PHONY: all run tags clean

all: ./bin/main_1 ./bin/main_2 ./bin/main_3

./bin/main_1: src/main_1.c
	@$(CC) $(CFLAGS) $^ -o $@

./bin/main_2: src/main_2.c
	@$(CC) $(CFLAGS) $^ -o $@

./bin/main_3: src/main_3.c
	@$(CC) $(CFLAGS) $^ -o $@

run1: ./bin/main_1
	@./bin/main_1

run1: ./bin/main_2
	@./bin/main_2

run3: ./bin/main_3
	@./bin/main_3

tags:
	ctags -R *

clean:
	rm -rf *.o *.c $(exec) tags