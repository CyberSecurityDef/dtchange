TARGET = dtchange
PREFIX = /usr/bin
CFLAGS = -Wall -Wextra
CC = gcc
OBJECTS = dtchange.o access.o modificed.o converter.o error.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
		$(CC) $(OBJECTS) -o $(TARGET)

access.o: access.c
		$(CC) $(CFLAGS) -c access.c

modificed.o: modificed.c
		$(CC) $(CFLAGS) -c modificed.c
		
converter.o: converter.c
		$(CC) $(CFLAGS) -c converter.c
		
error.o: error.c
		$(CC) $(CFLAGS) -c error.c
		
clean:
		rm -rf *.o dtchange
		
install:
		install $(TARGET) $(PREFIX)
		
uninstall:
		rm -rf $(PREFIX)/$(TARGET)
