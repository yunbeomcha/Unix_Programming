CC=gcc
CFLAGS=
OBJS=test1.o test2.o
LIBS=
all:    add

add:	$(OBJS)
	$(CC) $(CFLAGS) -o add $(OBJS) $(LIBS)

test1.o:	test1.c
	$(CC) $(CFLAGS) -c test1.c
test2.o:	test2.c
	$(CC) $(CFLAGS) -c test2.c
clean:
	rm -f $(OBJS) add

