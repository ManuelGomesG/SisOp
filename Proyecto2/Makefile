CC=gcc
CFLAGS=-g -Wall -std=c99 -pthread



usoDisco: main.c queues.o listing.o
	$(CC) $(CFLAGS) main.c queues.o listing.o -o $@

queues.o: queues.h queues.c
	$(CC) $(CFLAGS) -c queues.c -o queues.o

listing.o: listing.h listing.c 	
	$(CC) $(CFLAGS) -c listing.c  -o listing.o	

clean:
	rm -rf *.o usoDisco