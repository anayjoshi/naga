TARGET = naga
INSTALL_PATH = /usr/bin
CC=gcc
CFLAGS=-g
LIB = -lpthread -lncurses
.PHONY: clean uninstall test

SOURCES = src/main.c src/naga.c src/keypress.c src/curses_wrapper.c src/utils.c src/render.c src/engine.c
HEADERS = src/config.h src/curses_wrapper.h src/engine.h src/keypress.h src/naga.h src/render.h src/utils.h
TEST_SOURCES = src/tests/run_tests.c

OBJECTS = $(subst .c,.o,$(SOURCES))

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB) -o $(TARGET)
	
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)

install: $(TARGET) 
	@mv $(TARGET) $(INSTALL_PATH)

uninstall:
	rm -f $(INSTALL_PATH)/$(TARGET) 
