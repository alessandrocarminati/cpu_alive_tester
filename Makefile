BIN="cpu_tester"
INSTALL_DIR = $(PREFIX)/bin
all: main.c
	gcc -static main.c -o $(BIN)
install: all
	cp $(BIN) $(INSTALL_DIR)
