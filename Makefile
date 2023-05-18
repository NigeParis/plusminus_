EXEC=plusminus
CFLAGS=-Wall -Wextra -Werror
CC=gcc
FF=ft_plus_minus

.PHONY: run
run: $(EXEC)
	./$(EXEC)

$(EXEC): main.o $(FF).o
	$(CC) $^ -o $(EXEC)

main.o: main.c $(FF).h
	$(CC) $(CFLAGS) -c main.c

$(FF).o: $(FF).c
	$(CC) $(CFLAGS) -c $(FF).c

.PHONY: clean
clean:
	rm -rf $(EXEC) *.o

