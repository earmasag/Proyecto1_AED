DIR_OBJS = ./objs
OBJS = ./objs/main.o ./objs/donante.o 
BINARY = programa
CC = gcc

CFLAGS = -c -I/libs

programa: $(OBJS)
	gcc -o $(BINARY) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(DIR_OBJS)/$@

clean: 
	rm -f $(DIR_OBJS)/*.o programa