# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CC = gcc
# compiler to use

OBJ_DIR = obj
EXE_DIR = bin
SRC_DIR = src
UTIL_DIR = util
LIB_DIR = lib


LINKERFLAG = -lm

SRCS := foo.c
BINS := foo

all: problemThree

problemThree: $(EXE_DIR)/problemThree

execute : $(EXE_DIR)/problemThree
	./$(EXE_DIR)/problemThree


$(EXE_DIR)/problemThree: $(OBJ_DIR)/foo.o 
	@echo "Checking.."
	$(CC) $(OBJ_DIR)/*.o -lm -o $(EXE_DIR)/problemThree

$(OBJ_DIR)/foo.o: $(SRC_DIR)/main.c
	@echo "Creating object.."
	$(CC) -lm -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

clean:
	@echo "Cleaning up..."
	rm $(OBJ_DIR)/main.o 
	rm $(EXE_DIR)/problemThree