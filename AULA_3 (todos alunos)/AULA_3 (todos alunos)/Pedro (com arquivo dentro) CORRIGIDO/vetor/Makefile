CC ?= cc
CFLAGS ?= -Wall -Wextra -Werror

ifeq ($(OS),Windows_NT)
EXE_EXT = .exe
else
EXE_EXT =
endif

BIN_DIR = bin
BIN = $(BIN_DIR)/vetor$(EXE_EXT)

MENU_DIR = ../../utils/menu
MENU_LIB = $(MENU_DIR)/build/libmenu.a

SRCS = \
	main.c \
	vetor.c

.PHONY: all clean menu

all: $(BIN)

menu: $(MENU_LIB)

$(MENU_LIB):
	$(MAKE) -C $(MENU_DIR)

$(BIN): $(SRCS) $(MENU_LIB)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRCS) $(MENU_LIB) -o $(BIN)
	@echo "Executavel gerado em $(BIN)"

clean:
	rm -f $(BIN)
