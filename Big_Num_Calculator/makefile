all:
	gcc -c calculator.c -o calculator.o
	ar cr libarbprecision.a calculator.o
	gcc Ass4.c -L. -I. -larbprecision -lm -o mainfile

	