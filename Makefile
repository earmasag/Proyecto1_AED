DIR_OBJS = ./objs
OBJS = ./objs/main.o ./objs/donante.o 
BINARY = programa
CC = gcc

CFLAGS = -c -L/libs

programa: $(OBJS)
	gcc -o $(BINARY) $(OBJS)

$(DIR_OBJS)/main.o: main.c
	$(CC) $(CFLAGS) -o $@ $<

$(DIR_OBJS)/donante.o: donante.c
	$(CC) $(CFLAGS) -o $@ $<

clean: 
	rm -f $(DIR_OBJS)/*.o programa