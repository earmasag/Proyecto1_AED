DIR_BIN = bin
DIR_SRC = src
DIR_INC = inc
HEADERS = $(wildcard $(DIR_INC)/*.h)
SOURCES = $(wildcard $(DIR_SRC)/*.c)
OBJETOS = $(patsubst $(DIR_SRC)/%.c, $(DIR_BIN)/%.o, $(SOURCES)) 
BINARY = programa
CC = gcc

CFLAGS = -I./$(DIR_INC)/

all: programa

programa: $(OBJETOS)
	gcc -g -o $(BINARY) $^

$(DIR_BIN)/%.o: $(DIR_SRC)/%.c | $(DIR_BIN)
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_BIN):
	mkdir bin 

clean: 
	rm -f $(DIR_BIN)/*.o *.o programa