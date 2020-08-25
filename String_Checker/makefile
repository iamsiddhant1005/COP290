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


all:problemTwo

problemTwo: $(EXE_DIR)/problemTwo

$(EXE_DIR)/problemTwo : $(SRC_DIR)/Prob2b.l $(SRC_DIR)/Prob2b.y
	@lex $(SRC_DIR)/Prob2b.l
	@yacc $(SRC_DIR)/Prob2b.y
	@gcc y.tab.c -o $@ -ll -ly

execute: $(EXE_DIR)/problemTwo
	@./$<


clean: 
	@rm y.tab.c
	@rm $(EXE_DIR)/problemTwo