output: main.o inputfunction.o createnode.o
	cc main.o inputfunction.o createnode.o
main.o: main.c
	cc -c main.c
inputfunction.o: inputfunction.c Header.h
	cc -c inputfunction.c
createnode.o: createnode.c Header.h
	cc -c createnode.c
clean:
	rm -f *.o a.out
