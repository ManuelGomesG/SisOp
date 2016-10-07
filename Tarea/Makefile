CCFLAGS = -g -Wall -std=c99

prueba: main.c matrix.o graph_tree.o
	gcc $(CCFLAGS) main.c matrix.o graph_tree.o -o $@

graph_tree.o: graph_tree.h graph_tree.c 
	gcc -g -c -std=c99 graph_tree.c -o graph_tree.o

matrix.o: matrix.h matrix.c graph_tree.h
	gcc -g -c -std=c99 matrix.c -o matrix.o


clean:
	rm -rf *.o prueba


