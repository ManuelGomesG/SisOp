CCFLAGS = -g -Wall -std=c99 -pthread

batalla: main.c bombs.o
	gcc $(CCFLAGS) main.c bombs.o -o $@

bombs.o: bombs.h bombs.c 
	gcc -g -c -std=c99 bombs.c -o bombs.o


clean:
	rm -rf *.o batalla