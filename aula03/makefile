CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -lm -O2
OBJ = problema3.o
#==================================================
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

problema: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o problema
