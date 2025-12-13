CC = gcc
CFLAGS = -Iinclude -Wall -D_WIN32_WINNT=0x0600

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = contactbook

# Colors
BLUE   = \033[1;34m
GREEN  = \033[1;32m
YELLOW = \033[1;33m
RED    = \033[1;31m
RESET  = \033[0m

ifeq ($(OS),Windows_NT)
	SHELL_TYPE := $(shell echo $$SHELL)
	ifeq ($(SHELL_TYPE),)
		RM = del /F /Q
		EXE = $(TARGET).exe
		RUN = $(EXE)
		ECHO = @echo
	else
		RM = rm -f
		EXE = $(TARGET)
		RUN = ./$(EXE)
		ECHO = @echo -e
	endif
else
	RM = rm -f
	EXE = $(TARGET)
	RUN = ./$(EXE)
	ECHO = @echo -e
endif

all: $(TARGET)
	$(ECHO) "$(GREEN)$(EXE) has been created!$(RESET)"

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(EXE)
	$(ECHO) "$(BLUE)Linking... Done!$(RESET)"

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	$(ECHO) "$(BLUE)$< has been compiled to $@$(RESET)"

clean:
	$(RM) $(OBJ) $(EXE)
	$(ECHO) "$(RED)Cleaned$(RESET)"

run: $(TARGET)
	$(ECHO) "$(YELLOW)Running contactbook.exe...$(RESET)"
	$(RUN)
