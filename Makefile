BIN="cpu_tester"
INSTALL_DIR = $(PREFIX)/bin
all: main.c
	$(TOOLCHAIN_PREFIX)gcc -static main.c -o $(BIN)
install: all
	cp $(BIN) $(INSTALL_DIR)
