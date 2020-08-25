all: LEX YACC execute
LEX:
	lex lx.l
YACC:
	yacc -d yc.y
execute:
	gcc y.tab.c -lfl -ly -o conversion