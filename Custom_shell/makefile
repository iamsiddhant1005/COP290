CC = kcc
m.o:	2018CS10391_sh.c
	@echo "Creating Object.."
	$(CC) -c $^ -o m.o
	$(CC) m.o -o m.exe
	./m.exe
clean:
	rm -f m.o m.exe
