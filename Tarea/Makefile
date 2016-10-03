CCFLAGS = -g -Wall

prueba: main.c graph_tree.o
	gcc $(CCFLAGS) main.c graph_tree.o -o $@

graph_tree.o: graph_tree.h graph_tree.c
	gcc -g -c graph_tree.c -o graph_tree.o

clean:
	rm -rf *.o prueba

