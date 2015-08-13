CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -lm
OBJ = problema1.o
#==================================================
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

problema: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o problema 
