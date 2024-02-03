CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -std=c99 -g 
INC=-I /
SRC=prog
EXEC=main

all: $(EXEC)
 
main: $(SRC)prog.c $(SRC)go.o 
	$(CC) $(INC) -o $(SRC) $@ $^ $(CFLAGS) 
 
$(SRC)%.o : $(SRC)%.c
	$(CC) $(INC) -o $@ -c $< $(CFLAGS) 

clean:
	@rm -f *.o
	@rm -f core
	@rm -f *~