all: LEX EXE RUN
LEX:
	lex decomment.l
EXE:
	gcc lex.yy.c -o decomment
RUN:
	./decomment < input.txt > output.txt 2> error.txt
